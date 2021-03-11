#include <iostream>
using namespace std;

class Square
{
private:
    double dlugosc{};
public:
    Square();
    ~Square();

    Square(double dlugosc)
    {
        this->dlugosc = dlugosc;
    }

    static void pole(double dlugosc);

    static void obwod(double dlugosc);

};

void Square::pole(double dlugosc)
{
    double pole = dlugosc * dlugosc;
    cout << pole << endl;
}

void Square::obwod(double dlugosc)
{
    double obwod = dlugosc * 4;
    cout << obwod << endl;
}


Square::Square() {

}

class Circle
{
private:
    double promien;
public:
    Circle();
    ~Circle();

    Circle(double promien)
    {
        this->promien = promien;
    }

    static void pole(double promien);
    static void obwod(double promien);

};

Circle::Circle() {

}

void Circle::pole(double promien) {
    double pole = 3.14*promien*promien;
    cout << pole << endl;
}

void Circle::obwod(double promien) {
    double obwod = 2*3.14*promien;
    cout << obwod << endl;
}

int main(int argc, char *argv[])
{

    Square *kwadrat = new Square();

    kwadrat->pole(14);
    kwadrat->obwod(14);

    Circle *kolo = new Circle();

    kolo->pole(5);
    kolo->obwod(5);


}
