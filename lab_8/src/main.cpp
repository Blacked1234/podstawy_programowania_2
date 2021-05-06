#include <vector>
#include <iostream>

struct B {
    int m = 0;
    void hello() const {
        std::cout << "Hello world, this is B!\n";
    }
};

struct A;

struct D : B {
    void hello() const {
        std::cout << "Hello world, this is D!\n";
    }
};

enum class E { ONE = 1, TWO, THREE };

struct Base {
    virtual ~Base() {}
};

struct Derived: Base {
    virtual void name() {}
};

using namespace std;

class type
{
private:
    int att;
public:
    type(int t):att(t) {}

    // A const function that changes atribute with the help of const_cast
    void fun() const
    {
        int* ptr = const_cast<int*>(&att);
        *ptr = 5;
    }

    int getAtt()  { return att; }
};

int fun(int* ptr)
{
    *ptr = *ptr + 10;
    return (*ptr);
}

int main()
{
    // 1.1: initializing conversion - convert float 3.14 to int n and print n
    float liczbaPI = 3.14;
    int n = static_cast<int>(liczbaPI);
    std::cout << "n = " << n << '\n';

    // 1.2 initializing conversion - init 10 element vector using implicit conversion sequence and pring vector v size
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "v.size() = " << v.size() << '\n';

    // 2.1: static downcast - upcast via implicit conversion and call hello()
    D d;
    B& br = d; // upcast via implicit conversion
    br.hello();
    //B& br;
    // 2.2 downcast br to D and call hello()
    D& another_d = static_cast<D&>(br);
    another_d.hello();

    // 3: lvalue to xvalue - convert vector v from 1 to rvalue reference and print vector v size
    std::vector<int> v2 = static_cast<std::vector<int>&&>(v);
    std::cout << "after move, v.size() = " << v.size() << '\n';

    // 4: discarded-value expression - use static_cast in this context
    static_cast<void>(v2.size());

    // 5. inverse of implicit conversion - perform inverse conversion of nv using static_cast
    void* nv = &n;
    int* ni = static_cast<int*>(nv);
    std::cout << "*ni = " << *ni << '\n';

    // 6. array-to-pointer followed by upcast
    D a[10];
    B* dp = static_cast<B*>(a);

    // 7. scoped enum to int or float
    E e = E::ONE;
    int one = static_cast<int>(e);
    std::cout << one << '\n';

    // 8. void* to any type - voidp to p
    void* voidp = &e;
    std::vector<int>* p = static_cast<std::vector<int>*>(voidp);
    std::cout << p << endl;

    //D d1; // the most derived object
    //A& a1 = d1; // upcast, dynamic_cast may be used, but unnecessary
    //D& new_d = dynamic_cast<D&>(a); // downcast
    //B& new_b = dynamic_cast<B&>(a); // sidecast

    Base* b1 = new Base;
    // 9. Perform safe call of d->name() - convert b1 to d
    Derived* d2 = dynamic_cast<Derived*>(b1);
    // check pointer
    // d2->name(); // safe to call

    // 10. Perform safe call of d->name() - convert b2 to d
    Base* b2 = new Derived;
    Derived* d1 = dynamic_cast<Derived*>(b2);
    // check pointer
    d1->name(); // safe to call

    delete b1;
    delete b2;

    // 11. Modify att in t
    type t(3);
    cout << "Old att: " << t.getAtt() << endl;
    t.fun();
    cout << "New att: " << t.getAtt() << endl;

    // 12. Fix an error, uncomment fun(ptr)
    int val = 10;
    int *ptr = &val;
    fun(ptr);
    cout << val;

}