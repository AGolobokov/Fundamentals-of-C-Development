#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

int greatest_common_divisor(int a, int b) {
  int t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

// class Rational {
//     // Вставьте сюда реализацию класса Rational
//     public:
//     Rational() {
//         // Реализуйте конструктор по умолчанию
//         rational_numerator = 0;
//         rational_denominator = 1;
//     }

//     Rational(int numerator, int denominator) {
//         // Реализуйте 
//         rational_numerator = numerator;
//         rational_denominator = denominator;
//         if (denominator == 0) {
//             throw std::invalid_argument("Divide by zero exception");
//         }

//         if (numerator == 0) {
//             rational_numerator = 0;
//             rational_denominator = 1;
//         } else if (numerator < 0) {
//             rational_numerator = -numerator;
//             rational_denominator = -denominator;
//         }

//         int gcd = greatest_common_divisor(rational_numerator, rational_denominator);
//         rational_numerator = rational_numerator / gcd;
//         rational_denominator = rational_denominator / gcd;
//         if (rational_numerator > 0 && rational_denominator < 0) {
//             rational_numerator = -rational_numerator;
//             rational_denominator = -rational_denominator;
//         }
//     }

//     int Numerator() const {
//         // Реализуйте этот метод
//         return rational_numerator;
//     }

//     int Denominator() const {
//         // Реализуйте этот метод
//         return rational_denominator;
//     }
    
//     void SetNumerator(int n) {
//         rational_numerator = n;
//     }

//     void SetDenominator(int d) {
//         rational_denominator = d;
//     }

// private:
//     // Добавьте поля
//     int rational_numerator;
//     int rational_denominator;
// };


void TestSomething() {

    //auto
    Rational rational;
    AssertEqual(rational.Numerator(), 0);
    AssertEqual(rational.Denominator(), 1);

    Rational rationall(5,10);
    AssertEqual(rationall.Numerator(), 1);
    AssertEqual(rationall.Denominator(), 2);
    
    //
    Rational rational1(-6,8);
    AssertEqual(rational1.Numerator(), -3);
    AssertEqual(rational1.Denominator(), 4);
    
    Rational rational2(6,-8);
    AssertEqual(rational2.Numerator(), -3);
    AssertEqual(rational2.Denominator(), 4);

    Rational rational3(-6,-8);
    AssertEqual(rational3.Numerator(), 3);
    AssertEqual(rational3.Denominator(), 4);

    Rational rational4(0,12);
    AssertEqual(rational4.Numerator(), 0);
    AssertEqual(rational4.Denominator(), 1);
};

void TestAll() {
    TestRunner runner;
    runner.RunTest(TestSomething,"TestSomething");
};

int main() {
  TestRunner runner;
  runner.RunTest(TestSomething,"TestSomething");
  // добавьте сюда свои тесты
  return 0;
}
