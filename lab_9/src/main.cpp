#include <bitset>
#include <functional>
#include <iostream>

struct Base
{
    virtual ~Base()
    {
    }
};

struct Derived : Base
{
    virtual void name()
    {
        std::cout << "name()" << std::endl;
    }

};

// 6. Write a function: float division(int *num, int den)
// write your own expection class(es) to handle two kinds of exceptions
// throw when num is null or x == 0
// provide and extra info about the exception (message, line, function name,
// info) e.g throw myexception("msg", __FILE__,
// catch exceptions

struct ExceptMy : public std::exception{
    const char * what () const noexcept {
        return "Exception";
    }
};

float division(int *num, int den)
{
    try
    {
        if(num == NULL || den == 0)
        {
            throw ExceptMy();
        }
    }
    catch(ExceptMy &ex)
    {
        std::cout << ex.what() << std::endl;
    }

}

int main() {
    // 0. Solve the quiz
    // https://www.geeksforgeeks.org/c-plus-plus-gq/exception-handling-gq/

    // 1. Handle standard exceptions

    /*try {
        int *myarray = new int[1000000000000L];
    }
    catch(std::bad_alloc &e)
    {
        std::cout << e.what() << std::endl;
    }*/

    // 2. Handle standard exceptions
    try {
        Base b;
        Derived &f = dynamic_cast<Derived &>(b);
    }
    catch(std::bad_cast &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    // 3. Handle standard exceptions
    try {
        std::function<int(int, int)> add = std::plus<int>();
        std::function<int(int, int)> add2;

        std::cout << add(10, 20) << '\n';
        std::cout << add2(10, 20) << '\n';
    }
    catch(std::bad_function_call &e)
    {
        std::cout << e.what() << std::endl;
    }

    // 4. Handle standard exceptions
    try {
        Base *base = 0;
        typeid(*base);
    }
    catch(std::bad_typeid &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    // 5. Handle standard exceptions
    try {
        std::bitset<128> x(1);
        std::cout << x.to_ulong() << std::endl;
        x.flip();
        std::cout << x.to_ulong() << std::endl;
    }
    catch(std::overflow_error &e)
    {
        std::cout << e.what() << std::endl;
    }

    // 6. Write a function: float division(int *num, int den)
    // write your own expection class(es) to handle two kinds of exceptions
    // throw when num is null or x == 0
    // provide and extra info about the exception (message, line, function name,
    // info) e.g throw myexception("msg", __FILE__,
    // catch exceptions

    int *ptr = new int[1];
    division(ptr, 0);

}