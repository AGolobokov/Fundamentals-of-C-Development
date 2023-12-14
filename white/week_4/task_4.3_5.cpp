#include <iostream>
#include <sstream>
using namespace std;

int greatest_common_divisor(int a, int b) {
  int t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        rational_numerator = 0;
        rational_denominator = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте 
        rational_numerator = numerator;
        rational_denominator = denominator;

        if (numerator == 0) {
            rational_numerator = 0;
            rational_denominator = 1;
        } else if (numerator < 0) {
            rational_numerator = -numerator;
            rational_denominator = -denominator;
        }

        int gcd = greatest_common_divisor(rational_numerator, rational_denominator);
        rational_numerator = rational_numerator / gcd;
        rational_denominator = rational_denominator / gcd;
        if (rational_numerator > 0 && rational_denominator < 0) {
            rational_numerator = -rational_numerator;
            rational_denominator = -rational_denominator;
        }
    }

    int Numerator() const {
        // Реализуйте этот метод
        return rational_numerator;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return rational_denominator;
    }

private:
    // Добавьте поля
    int rational_numerator;
    int rational_denominator;
};

// Реализуйте для класса Rational операторы ==, + и -

bool operator==(Rational r1, Rational r2) {
    if (r1.Numerator() == r2.Numerator() && r1.Denominator() == r2.Denominator()) {
        return true;
    }
    return false;
};


Rational operator+(Rational r1, Rational r2) {

    if (r1.Denominator() == r2.Denominator()) {
        return Rational(r1.Numerator() + r2.Numerator(), r1.Denominator());
    } else {
        return Rational(r1.Numerator()*r2.Denominator() + r2.Numerator()*r1.Denominator(), r1.Denominator()*r2.Denominator());
    }
};

Rational operator-(Rational r1, Rational r2) {
    if (r1.Denominator() == r2.Denominator()) {
        return Rational(r1.Numerator() - r2.Numerator(), r1.Denominator());
    } else {
        return Rational(r1.Numerator()*r2.Denominator() - r2.Numerator()*r1.Denominator(), r1.Denominator()*r2.Denominator());
    }
};

Rational operator*(Rational r1, Rational r2) {
    return Rational(r1.Numerator()*r2.Numerator(), r1.Denominator()*r2.Denominator());
    
};

Rational operator/(Rational r1, Rational r2) {
    return Rational(r1.Numerator()*r2.Denominator(), r1.Denominator()*r2.Numerator());
};

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}

