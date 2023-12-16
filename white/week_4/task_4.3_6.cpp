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


ostream& operator<<(ostream& stream, Rational r) {
    stream <<r.Numerator();
    stream << "/";
    stream <<r.Denominator();
    return stream;
};

istream&  operator>>(istream& stream, Rational &r) { 
    int n, d = 0;
    if (stream.peek() != -1) {
        stream >> n;
        // cout << " N = " << n << endl;
        
        if (stream.peek() == '/') {
            stream.ignore();
        } 
        stream >> d;
        // cout << " D = " << d << endl;
        Rational x(n, d);
        r.SetNumerator(x.Numerator());
        r.SetDenominator(x.Denominator());
    }

    return stream;
};

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
           cout << "5/7 is incorrectly read as " << r << endl;
           return 2;
       }
    }

    {
        // cout << " W "<< endl;
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        // cout << "r1 = " << r1.Numerator() << r1.Denominator() << endl;
        // cout << "r2 = " << r2.Numerator() << r2.Denominator() << endl;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    // Rational r;
    // cout << r.Numerator() << r.Numerator()<< endl;
    // cin >> r;
    // cout << r;

    cout << "OK" << endl;
    return 0;
}