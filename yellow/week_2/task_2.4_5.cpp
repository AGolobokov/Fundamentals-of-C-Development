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


bool IsPalindrom(const string& str) {
    string str_copy = str;
    if (str.size() == 1 || str.size() == 0) {
        return true;
    }
    else if (str.size() > 1) {
        for (int i = 0; i <= str.size()/2 - 1; i++) {

            if (str[i] != str[str.size()-1 - i]) {
                return false;
            }
        }
        return true;
        
    }
    return false;
};



void TestSomething() {

    AssertEqual(IsPalindrom(""), true);
    AssertEqual(IsPalindrom("madam"), true);
    AssertEqual(IsPalindrom("ma"), false);
    AssertEqual(IsPalindrom(" "), true);
    AssertEqual(IsPalindrom(" awa "), true);
    AssertEqual(IsPalindrom(" aw a "), false);
    AssertEqual(IsPalindrom(" madam"), false);
    AssertEqual(IsPalindrom("madam "), false);
    AssertEqual(IsPalindrom(" level "), true);
    AssertEqual(IsPalindrom("level!"), false);
    AssertEqual(IsPalindrom("!level!"), true);
    AssertEqual(IsPalindrom("!==!"), true);
    
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
