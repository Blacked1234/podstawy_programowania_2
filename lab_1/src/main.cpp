#include <iostream>
using namespace std;

void add1(int A, int B, int *C);
void add2(const int *A, const int *B, int *C);
void add3(int &A, int &B, int *C);
void add4(int tablA[], int tablB[], int* tablC);
void add5(int *tablA, int *tablB, int* tablC);

int main(int argc, char *argv[])
{
    int A = 5;
    int B = 10;
    int C;
    add1(A, B, &C);
    add2(&A, &B, &C);
    add3(A, B, &C);
    int tabA[10];
    for(int i = 0; i<10; i++)
    {
        tabA[i] = i+1;
    }
    int tabB[10];
    for(int i = 0; i<10; i++)
    {
        tabB[i] = i+1;
    }
    int tabC[10];
    for(int i = 0; i<10; i++)
    {
        tabC[i] = i+1;
    }
    add4(tabA, tabB, tabC);
    add5(tabA, tabB, tabC);

    return 0;
}

void add1(int A, int B, int* C)
{
    *C = A + B;
    cout << *C << endl;;
}

void add2(const int* A, const int* B, int* C)
{
    *C = *A + *B;

    cout << *C << endl;;
}

void add3(int &A, int &B, int* C)
{
    *C = *&A + *&B;

    cout << *C << endl;;
}

void add4(int tablA[], int tablB[], int* tablC)
{
    for(int i = 0; i<10; i++)
    {
        tablC[i]=tablA[i]+tablB[i];
        cout << tablC[i] << endl;
    }

}

void add5(int *tablA, int *tablB, int* tablC)
{
    for(int i = 0; i<10; i++)
    {
        tablC[i]=tablA[i]+tablB[i];
        cout << tablC[i] << endl;
    }
}
