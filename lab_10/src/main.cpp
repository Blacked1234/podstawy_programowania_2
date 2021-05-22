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

    VectoredList(){
        tail = nullptr;
        size = 0;
        capacity = 0;
        head = tail;
    }
    ~VectoredList(){
        while(head){
            Bucket * tmp = head->nastepny;
            delete head;
            head = tmp;
        }
    }

    void push_back(string newelement)
    {
        if(tail) {
            if (tail->count < tail->N) {
                tail->elementy[tail->count] = newelement;
                ++(tail->count);
            } else {
                Bucket *nowy = new Bucket();
                tail->nastepny = nowy;
                nowy->poprzedni = tail;
                tail = nowy;
                capacity += tail->N;
                tail->elementy[0] = newelement;
                size++;
                ++(tail->count);
            }
        }
        Bucket *nowy = new Bucket();
        tail = nowy;
        head = tail;
        nowy->poprzedni = tail;
        tail = nowy;
        capacity += tail->N;
        tail->elementy[0] = newelement;
        size++;
        ++(tail->count);
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
    int VectoredListSize(){
        return capacity - (tail->N - tail->count);
    }
};


int main()
{
    cout << endl << "---------- 1,2 ----------" << endl;

    VectoredList v;
    for (int i = 0; i < 101; ++i) {
        v.push_back("s" + to_string(i));
    }

    for (VectoredList::VectoredListIterator ita(v, 101); ita.good(); --ita)
    {
        cout << ita.get() << " ";
        if (ita.cur % 10 == 0)
            cout << endl;
    }

    cout << endl << "---------- 3 ----------" << endl;;
    for (const auto &element : v)
         cout << element << "AAA" << endl;

    cout << endl << "---------- 4 ----------" << endl;
    // VectoredList::VectoredListIterator it3(v, 3);
    // VectoredList::VectoredListIterator it33(v, 33);
    // VectoredList::VectoredListIterator it45(v, 45);

    // v.erase(it3);
    // v.pop_back();
    // v.pop_back();
    // v.erase(it33, it45);
    // for (int i = 0; i < v.VectoredListSize(); ++i)
    // {
    //     cout << v[i] << " ";
    //     if (i % 10 == 0)
    //         cout << endl;
    // }

    cout << endl << "---------- 5 ----------" << endl;
    VectoredList v2 = v;
    for (int i = 0; i < v2.VectoredListSize(); ++i)
    {
         cout << v2[i] << " ";
         if (i % 10 == 0)
            cout << endl;
    }
}