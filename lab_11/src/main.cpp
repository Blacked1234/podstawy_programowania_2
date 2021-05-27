#include <vector>
#include <iostream>
using namespace std;

class IndexOutOfBound{};
class VectoredList {
    class Bucket{
    private:
    public:
        int count = 0;
        Bucket * poprzedni;
        Bucket * nastepny;
        static const int N = 10;
        vector<string> elementy;

        Bucket()
        {
            elementy.resize(N);
        }
        ~Bucket()
        {
            delete poprzedni;
            delete nastepny;
        }
    };
public:
    Bucket * head;
    Bucket * tail;
    int size = 0;
    int capacity = 0;


    VectoredList()
    {
        tail = nullptr;
        size = 0;
        capacity = 0;
        head = tail;
    }

    VectoredList(const VectoredList &s){
        head = nullptr;
        tail = nullptr;
        size = 0;
        capacity = 0;

        for(VectoredListIterator i(s, 0); i.good(); ++i)
        {
            push_back(i.get());
        }
    }

    VectoredList(VectoredList &&v) : head(nullptr), tail(nullptr), size(0), capacity(0)
    {
        head = nullptr;
        size = 0;
        tail = nullptr;
        capacity = 0;
        //*this = move(v);
        for(VectoredListIterator i(v, 0); i.good(); ++i)
        {
            push_back(i.get());
        }
        v.head = nullptr;
        v.size = 0;
        v.tail = nullptr;
        v.capacity = 0;
    }

    VectoredList& operator=(VectoredList &&v) {
        if(this != &v)
        {
            head = nullptr;
            size = 0;
            tail = nullptr;
            capacity = 0;
            //*this = move(v);
            for(VectoredListIterator i(v, 0); i.good(); ++i)
            {
                push_back(i.get());
            }
            v.head = nullptr;
            v.size = 0;
            v.tail = nullptr;
            v.capacity = 0;
        }
        return *this;
    }

    ~VectoredList(){
        while(head){
            Bucket * tmp = head->nastepny;
            delete head;
            head = tmp;
        }
    }

    VectoredList operator+(const VectoredList &rhs) const
    {
        VectoredList new_(*this);
        for(int i = 0; i < rhs.VectoredListSize(); i++)
        {
            new_.push_back(rhs[i]);
        }
        return new_;
    }

    void assign(vector<string> v)
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
        capacity = 0;
        for(auto s : v)
        {
            this->push_back(s);
        }
    }

    bool push_back(string newelement){
        if(head)
        {
            if(tail->count < tail->N)
            {
                tail->elementy[tail->count++] = newelement;
                return 1;
            }
            else
            {
                Bucket * newBucket = new Bucket();
                newBucket->poprzedni = tail;
                newBucket->nastepny = nullptr;
                tail->nastepny = newBucket;
                tail = newBucket;
                capacity += tail->N;
                tail->elementy[tail->count++] = newelement;
                size++;
                return 1;
            }
        }
        else
        {
            head = tail = new Bucket();
            head->nastepny = tail;
            head->poprzedni = nullptr;
            tail->nastepny = nullptr;
            tail->poprzedni = head;
            capacity += tail->N;
            head->elementy[head->count++] = newelement;
            size++;
            return 1;
        }
        return 0;
    }


    string operator[](int index)const
    {
        if(index >= capacity){
            return NULL;
        }
        int ind = 0;
        Bucket *it = head;
        while(!(ind <= index && it->N + ind > index))
        {
            ind += it->N;
            it = it->nastepny;
        }
        return it->elementy[index - ind];
    }

    class VectoredListIterator{
        const VectoredList & v;
    public:
        int cur;
        VectoredListIterator(const VectoredList & l, int index): v(l), cur(index)
        {}
        VectoredListIterator & operator--()
        {
            cur--;
            return *this;
        }
        VectoredListIterator & operator++()
        {
            cur++;
            return *this;
        }
        string get() const
        {
            if(this->good())
                return v[cur];
            else
                return 0;
        }
        bool good()const
        {
            if(cur<v.capacity && cur >= 0)
                return 1;
            else
                return 0;
        }
        bool operator!=(VectoredListIterator a)
        {
            if(this->get() == a.get())
                return 0;
            else
                return 1;
        }
        string operator*(){return v[cur];}
    };
    VectoredListIterator begin()
    {
        return VectoredListIterator(*this,0);
    }
    VectoredListIterator end(){
        return VectoredListIterator(*this, this->size - 1);
    }
    int VectoredListSize() const{
        return capacity - (tail->N - tail->count);
    }
};


int main()
{
    cout << endl << "---------- 1 ----------" << endl;
    VectoredList v;
    string       t11("TEST 1.1");
    string       t12("TEST 1.2");
    v.push_back(t11);
    v.push_back(t12);


    VectoredList v1(move(v));


    for (int i = 0; i < v1.VectoredListSize(); ++i)
    {
         cout << v1[i] << endl;
    }

    cout << endl << "---------- 2 ----------" << endl;
    VectoredList v2;
    string       t21("TEST 2.1");
    string       t22("TEST 2.2");
    v2.push_back(t21);
    v2.push_back(t22);

    v1 = move(v2);

    for (int i = 0; i < v1.VectoredListSize(); ++i)
    {
       cout << v1[i] << endl;
    }

    cout << endl << "---------- 3 ----------" << endl;
    VectoredList v3, v4;
    string       t31("TEST 3.1");
    v3.push_back(t31);

    v4 = v1 + v3;

    for (int i = 0; i < v4.VectoredListSize(); ++i)
    {
        cout << v4[i] << endl;
    }

    cout << endl << "---------- 4 ----------" << endl;
    vector<string> V{"TEST 4.1", "TEST 4.2"};

    v4.assign(V);

    for (int i = 0; i < v4.VectoredListSize(); ++i)
    {
        cout << v4[i] << endl;
    }
}