#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include <stack>
#include <iomanip>
#include <cmath>

using namespace std;

#define PI 3.14

class Figure {
    public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle: public Figure {
    public:
    Triangle(double v1, double v2, double v3) : a(v1), b(v2), c(v3) {}
    string Name() const override {
        return "TRIANGLE";
    }
    double Perimeter() const override {
        return (a + b + c);
    }
    double Area() const override {
        double p = (a + b + c)/2;
        return sqrt(p * (p - a)*(p - b)*(p - c));
    }
    private:
    double a;
    double b;
    double c;
};

class Rect: public Figure  {
    public:
    Rect(double w, double h) : width(w), height(h) {}
    string Name() const override {
        return "RECT"; 
    }
    double Perimeter() const override {
        return (width + height) * 2;
    }
    double Area() const override {
        return width * height;
    }
    private:
    double width; 
    double height;
};

class Circle: public Figure  {
    public:
    Circle (double rad) : r(rad) {}
    string Name() const {
        return "CIRCLE"; 
    }
    double Perimeter() const {
        return 2*PI*r;
    }
    double Area() const {
        return PI*r*r;
    }
    private:
    double r;
}; 

shared_ptr<Figure> CreateFigure(istringstream & is) {
    string fname;
    is >> fname;
    if (fname == "RECT") {
        double rec1, rec2 = 0;
        is >> rec1;
        is >> rec2;
        // Rect rect(rec1, rec2);
        return make_shared<Rect>(rec1, rec2);

    } else if (fname == "TRIANGLE") {
        double tr1, tr2, tr3 = 0;
        is >> tr1;
        is >> tr2;
        is >> tr3;
        // Triangle triangle(tr1, tr2, tr3);
        return make_shared<Triangle>(tr1, tr2, tr3);
    } else if (fname == "CIRCLE") {
        double cr1 = 0;
        is >> cr1;
        // Circle circle(cr1);
        return make_shared<Circle>(cr1);
    }
};

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}