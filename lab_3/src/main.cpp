#include <iostream>
#include <cmath>

class Square {
private:
    double side;
    double x = 5;
    double y = 5;
    // Wspolrzedne
public:
    static double count;
    Square(double _side_) {
        count++;
        side = _side_;
        std::cout << "Object Square created" << std::endl;
    }
    ~Square() {
        count--;
        std::cout << "Object Square destroyed" << std::endl;
    }
    Square(const Square &sqr1) { side = sqr1.side; }
    double getCircumference() const { return 4 * side; }
    double getArea() const { return side * side; }
    double getSide() const { return side; }
    double getPositionX() const { return x; }
    double getPositionY() const { return y; }
};

double Square::count = 0;

class Circle {
private:
    double radius;
    double x = 10;
    double y = 10;
    // Wspolrzedne
public:
    Circle(double _radius_) {
        radius = _radius_;
        std::cout << "Object Circle created" << std::endl;
    }
    ~Circle() { std::cout << "Object Circle destroyed" << std::endl; }
    Circle(const Circle &cir1) { radius = cir1.radius; }
    double getCircumference() const { return 2 * M_PI * radius; }
    double getArea() const { return M_PI * radius * radius; }
    double getRadius() const { return radius; }
    double getPositionX() const { return x; }
    double getPositionY() const { return y; }
    static double print_pi() { std::cout << "Pi is " << M_PI << std::endl; }
};

class Drawing {
private:
    double wysokosc = 20;
    double szerokosc = 20;
    Circle *c1 = new Circle(5);
    Square *s1 = new Square(5);
    // Kwadrat i Kolo
    // Rozmiar plotna

public:
    Drawing(double _wysokosc_, double _szerokosc_)
    {
        wysokosc = _wysokosc_;
        szerokosc = _szerokosc_;
        std::cout << "Obrazek utworzony!" << std::endl;
    }
    Drawing(const Drawing &draw1)
    {
        wysokosc = draw1.wysokosc;
        szerokosc = draw1.szerokosc;
        std::cout << "Utworzono osoby obrazek!" << std::endl;
    }
    // Konstruktory
    ~Drawing()
    {
        std::cout << "Obrazek zniszczony!" << std::endl;
        delete s1;
        delete c1;
    }
    // Destruktor
    // Pobierz Informacje

    void info();

};

void Drawing::info() {
    std::cout << "Wysokosc i szerokosc obrazka: " << wysokosc << " " << szerokosc << std::endl;
    std::cout << "Promien kola: " << c1->getRadius() << std::endl;
    std::cout << "Obwod kola: " << c1->getCircumference() << std::endl;
    std::cout << "Pole kola: " << c1->getArea() << std::endl;
    std::cout << "Wspolrzedne kola x i y: " << c1->getPositionX() << " " << c1->getPositionY() << std::endl;
    std::cout << "Dlugosc kwadratu: " << s1->getSide() << std::endl;
    std::cout << "Obwod kwadratu: " << c1->getCircumference() << std::endl;
    std::cout << "Pole kwadratu: " << s1->getArea() << std::endl;
    std::cout << "Wspolrzedne kwadratu x i y: " << s1->getPositionX() << " " << s1->getPositionY() << std::endl;
}

int main(int argc, char *argv[])
{
    Drawing *d1 = new Drawing(20, 20);
    d1->info();
    delete d1;
    return 0;
}
