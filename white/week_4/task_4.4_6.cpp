#include <iostream>
#include <exception>
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
    // Вставьте сюда реализацию класса Rational
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
        if (denominator == 0) {
            throw std::invalid_argument("Divide by zero exception");
        }

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
    
    void SetNumerator(int n) {
        rational_numerator = n;
    }

    void SetDenominator(int d) {
        rational_denominator = d;
    }

private:
    // Добавьте поля
    int rational_numerator;
    int rational_denominator;
};

// Вставьте сюда реализацию operator / для класса Rational
Rational operator/(Rational r1, Rational r2) {
    if (r2.Numerator() == 0) {
        throw std::domain_error("Divide by zero exception");
    }
    return Rational(r1.Numerator()*r2.Denominator(), r1.Denominator()*r2.Numerator());
};

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
