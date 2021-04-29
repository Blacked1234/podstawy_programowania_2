#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <list>
#include <memory>
#include <typeinfo>
using namespace std;

class Figure {
    string type;
    class Point2D {
    public:
        int x_ob;
        int y_ob;
        Point2D() {
            x_ob = 0;
            y_ob = 0;
        }
        double getPtX() { return x_ob; };
        double getPtY() { return y_ob; };
        Point2D(int _x, int _y) {
            x_ob = _x;
            y_ob = _y;
        }
        void setPtXY(int x, int y) {
            x_ob = x;
            y_ob = y;
        }
    };
    Point2D coord;

public:
    Figure() {
        coord.x_ob = 0;
        coord.y_ob = 0;
    }
    virtual void draw() const = 0;
    virtual double getLength() const
    {
        return 0;
    }
    string getType() const
    {
        return type;
    }
    virtual ~Figure() = default;
    void setXY(int _x, int _y) { coord.setPtXY(_x, _y); }
    void setType(const char *n) { type = n; }
    void getCo() { cout << "(" << coord.x_ob << " , " << coord.y_ob << ")"; }
    virtual double getArea() const { return 0; };
    virtual double getCircumference() { return 0; };
    Figure(const Figure &f) {
        this->setXY(f.getX(), f.getY());
        this->type = f.type;
    }
    double getX() const { return this->coord.x_ob; }
    double getY() const { return this->coord.y_ob; }
};

class Square : public Figure {
private:
    string type = "Square";
    double side = 5;

public:
    static double count;

    Square(const Square &sq) : Figure(sq) {
        this->side = sq.side;
        count++;
    }

    Square(double _side_, int x, int y) {
        count++;
        side = _side_;
        std::cout << "Object Square created" << std::endl;
        this->setType("Square");
        this->setXY(x, y);
    }
    Square() {
        count++;
        this->setType("Square");
    };
    ~Square() {
        count--;
        std::cout << "Object Square destroyed" << std::endl;
    }
    double getCircumference() override { return 4 * side; }
    double getArea() const override { return side * side; }
    double getSide() { return side; }
    void set(double n) { side = n; }

    void changePosS(int a, int b) { this->setXY(a, b); }

    void draw() const {
        cout << getType() << endl;
        cout << getArea() << endl;
    }
};

double Square::count = 0;


class Circle : public Figure {
private:
    double radius = 10;

public:
    Circle(const Circle &cir) : Figure(cir) { this->radius = cir.radius; }
    Circle(double _radius_, int x, int y) {
        radius = _radius_;
        std::cout << "Object Circle created" << std::endl;
        this->setXY(x, y);
        this->setType("Circle");
    }
    Circle() {
        this->setType("Circle");
        this->setXY(0, 0);
    };
    ~Circle() { std::cout << "Object Circle destroyed" << std::endl; }
    double getCircumference() override { return 2 * M_PI * radius; }
    double getArea() const override { return M_PI * radius * radius; }
    static void print_pi() { std::cout << "Pi is " << M_PI << std::endl; }
    void set(double n) { radius = n; }
    double getRadius() { return radius; }
    void changePosC(int a, int b) { this->setXY(a, b); }
    void draw() const {
        cout << getType() << endl;
        cout << getArea() << endl;
    }
};


class Drawing {
private:
    int r_x, r_y;

public:
    list<Figure *> figureList;
    Drawing() {
        r_x = 20;
        r_y = 20;
    };
    Drawing(int _rx, int _ry) {
        r_x = _rx;
        r_y = _ry;
        cout << "Drawing has been created." << endl;
    }
    Drawing(const Drawing &f){};
    ~Drawing() {
        cout << endl << "Clear the list." << endl;
        for(auto object: figureList)
        {
            delete object;
        }
    }
    Drawing *deepcopy(const Drawing *copy) { return new Drawing(*copy); }
    void setSize(int rx, int ry) {
        r_x = rx;
        r_y = ry;
    }
    void addObject(Figure *fig) { figureList.push_back(fig); };
    void addFigure(Figure *ab) { figureList.push_back(ab); };
    void printList() {
        cout << endl << "List of elements: " << endl;
        for (auto const &v : figureList) {
            cout << "Figure type: ";
            v->getType();
            cout << " ";
            cout << endl << "Co-ordinates: ";
            v->getCo();
            cout << endl;
            cout << "Area: " << v->getArea()
                 << " Circumference: " << v->getCircumference() << endl
                 << endl;
        }
        cout << endl;
    }
    void eraser(int idx) {
        list<Figure *>::iterator itr = figureList.begin();
        advance(itr, idx);
        figureList.erase(itr);
    }
};

// bool PComp(const Figure *const &a, const Figure *const &b) { return *a < *b;
// }

enum ProductTypeE { E_UNKNOWN, E_PRODUCT_1, E_PRODUCT_2, E_PRODUCT_3 };

class StraightLine : public Figure
{
private:
    double length;
public:
    StraightLine(double _len)
    {
        length = _len;
        this -> setType("CurvedLine");
    }
    ~StraightLine()
    {
        cout << "CurvedLine destroyed!\n" << endl;
    }
    void draw() const {
        cout << getType() << endl;
        cout << getLength() << endl;
    }
};

class CurvedLine : public Figure
{
private:
    double length;
public:
    CurvedLine(double _len)
    {
        length = _len;
        this -> setType("CurvedLine");
    }
    ~CurvedLine()
    {
        cout << "CurvedLine destroyed!\n" << endl;
    }
    void draw() const {
        cout << getType() << endl;
        cout << getLength() << endl;
    }
};

class Painter
{
private:
    Drawing* drawing;
public:
    Painter(Drawing *draw): drawing(draw) {}
    virtual ~Painter(){}
    virtual Figure* createFigure() = 0;
    void printMyWork()
    {
        for(auto fig: drawing->figureList)
        {
            fig->draw();
        }
    }
    void draw(){
        Figure* fig = createFigure();
        fig -> draw();
        drawing -> addObject(fig);
    }

};

class CirclePainter : public Painter
{
public:
    CirclePainter(Drawing *draw): Painter(draw) {}
    ~CirclePainter() { cout << "CirclePainter destroy!\n" << endl; }
    Figure* createFigure() override
    {
        return new Circle();
    }
};

class SquarePainter : public Painter
{
public:
    SquarePainter(Drawing *draw): Painter(draw) {}
    ~SquarePainter() { cout << "SquarePainter destroy!\n" << endl; }
    Figure* createFigure() override
    {
        return new Square();
    }

};

class StraightLinePainter : public Painter
{
public:
    StraightLinePainter(Drawing *draw): Painter(draw) {}
    ~StraightLinePainter() { cout << "StraightLine destroy!\n" << endl; }
    Figure* createFigure() override
    {
        return new StraightLine(5);
    }
};

class CurvedLinePainter : public Painter
{
public:
    CurvedLinePainter(Drawing *draw): Painter(draw) {}
    ~CurvedLinePainter() { cout << "CurvedLine destroy!\n" << endl; }
    Figure* createFigure() override
    {
        return new CurvedLine(5);
    }
};


int main(int argc, char *argv[]) {

    Drawing* drawing1 = new Drawing();

    Painter *paint = new CirclePainter(drawing1);
    paint -> draw();

    Painter *paint1 = new StraightLinePainter(drawing1);
    paint1 -> draw();

    paint -> printMyWork();


    return 0;
}