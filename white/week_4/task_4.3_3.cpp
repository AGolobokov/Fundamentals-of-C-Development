#include <iostream>

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

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}

