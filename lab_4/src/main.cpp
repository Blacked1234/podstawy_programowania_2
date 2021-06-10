#include <iostream>
#include <cmath>
#include <vector>

class Figure
{
public:
    double x;
    double y;
    Figure()
    {
        std::cout << "Figure created!" << std::endl;
    }

    void draw()
    {
        std::cout << "Narysowano figure!" << std::endl;
    }

    void setPosition(double x1, double y1)
    {
        x = x1;
        y = y1;
    }

};

class Square: public Figure {
private:
    double side;
    // Wspolrzedne
public:
    static double count;
    Square(double _side_, double xs, double ys) {
        count++;
        side = _side_;
        x = xs;
        y = ys;
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

    void draw()
    {
        std::cout << "Narysowano kwadrat!" << std::endl;
    }
};

double Square::count = 0;

class Circle: public Figure {
private:
    double radius;
    // Wspolrzedne
public:
    Circle(double _radius_, double xc, double yc) {
        radius = _radius_;
        x = xc;
        y = yc;
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

    void draw()
    {
        std::cout << "Narysowano kolo!" << std::endl;
    }
};

class Drawing {
private:
    double x = 200;
    double y = 200;
    std::vector <Square> lista_kwadratow;
    std::vector <Circle> lista_kol;
    // Kwadrat i Kolo
    // Rozmiar plotna

public:
    Drawing(double _wysokosc_, double _szerokosc_)
    {
        y = _wysokosc_;
        x = _szerokosc_;
        std::cout << "Obrazek utworzony!" << std::endl;
    }
    Drawing(const Drawing &draw1)
    {
        y = draw1.y;
        x = draw1.x;
        std::cout << "Utworzono osoby obrazek!" << std::endl;
    }
    // Konstruktory
    ~Drawing()
    {
        std::cout << "Obrazek zniszczony!" << std::endl;
    }
    // Destruktor
    // Pobierz Informacje

    bool checkVar(double xc, double yc)
    {
        if(xc >= 0 && xc <= x && yc >=0 && yc <= y)
        {
            return true;
        }
        std::cout << xc << " " << yc << " " << y << " " << x << std::endl;
        return false;
    }

    void addCircle(double _radius_, double xc, double yc){
        if(checkVar(xc, yc)) {
            Circle *c1 = new Circle(_radius_, xc, yc);
            lista_kol.push_back(*c1);
            std::cout << "Wspolrzedne: " << xc << ", " << yc << std::endl;
            c1->draw();
            delete c1;
        }
    }

    void addSquare(double _side_, double xs, double ys) {
        if(checkVar(xs, ys)) {
            Square *s1 = new Square(_side_, xs, ys);
            lista_kwadratow.push_back(*s1);
            s1->draw();
            delete s1;
        }
    }

    void setPosition(double x1, double y1, int index, bool czyKolo)
    {
        if(checkVar(x1, y1)) {
            if(czyKolo && index<lista_kol.size())
            {
                lista_kol[index].setPosition(x1, y1);
                std::cout << "Zmieniono wspolrzedne kola: " << x1 << ", " << y1 << std::endl;
            }
            else if(!czyKolo && index<lista_kwadratow.size())
            {
                lista_kwadratow[index].setPosition(x1, y1);
                std::cout << "Zmieniono wspolrzedne kwadratu: " << x1 << ", " << y1 << std::endl;
            }
        }
    }

};


int main(int argc, char *argv[])
{
    Drawing *d1 = new Drawing(30, 30);
    d1->addCircle(5, 10, 20);
    d1->addSquare(10, 20, 5);
    d1->setPosition(5, 4, 0, true);

    delete d1;
    return 0;
}