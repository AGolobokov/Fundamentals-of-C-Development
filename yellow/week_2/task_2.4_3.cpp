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

// class Person {
// public:
//   string incognito = "Incognito";
//   void ChangeFirstName(int year, const string& first_name) {
//     // добавить факт изменения имени на first_name в год year
//     vector<string> v(2);
//     if (person_data.count(year) != 0) {
//         for (const auto &item: person_data) {
//             if (item.first == year) {
//                 v[1] = item.second[1];
//                 break;
//             }
//         }
//     }
//     v[0] = first_name;
//     person_data[year] = v;
//   }
//   void ChangeLastName(int year, const string& last_name) {
//     // добавить факт изменения фамилии на last_name в год year
//     vector<string> v(2);
//     if (person_data.count(year) != 0) {
//         for (const auto &item: person_data) {
//             if (item.first == year) {
//                 v[0] = item.second[0];
//                 break;
//             }
//         }
//     }
//     v[1] = last_name;
//     person_data[year] = v;
//   }
//   string GetFullName(int year) {
//     // получить имя и фамилию по состоянию на конец года 
//     if (person_data.size() != 0) {
//         string str = "";
//         vector<string> result(2);
//         map<int, vector<string>> reserv; 
//         if (person_data.count(year) != 0) {
//             for (const auto &item : person_data) {
//                 if (item.first == year) {
//                     if (item.second[0] != "") {
//                         result[0] = item.second[0];
//                     }
//                     if (item.second[1] != "") {
//                         result[1] = item.second[1];
//                     }
//                     break;
//                 } else {
//                     if (item.second[0] != "") {
//                         result[0] = item.second[0];
//                     }
//                     if (item.second[1] != "") {
//                         result[1] = item.second[1];
//                     }
//                 }
//             }
            
//             if (result[0] == "" || result[1] == "") {
//                 if (result[0] != "") {
//                     str.append(result[0]);
//                     str.append(" with unknown last name");
                    
//                 } else if (result[1] != "") {
//                     str.append(result[1]);
//                     str.append(" with unknown first name");
//                 }
//             } else {
//                 str.append(result[0]);
//                 str.append(" ");
//                 str.append(result[1]);
//             }
//         }
//         else {
//             vector<int> years;
//             for (const auto &item : person_data) {
//                 years.push_back(item.first);
//             }
//             if (year < years[0]) {
//                 // cout << "Incognito";// << endl;
//                 return incognito;
//             } else {
//                 for (const auto &item : person_data) {
//                     if (item.first < year) {
//                         if (item.second[0] != "") {
//                             result[0] = item.second[0];
//                         }
//                         if (item.second[1] != "") {
//                             result[1] = item.second[1];
//                         }
//                     } else {
//                         break;

//                     }
                
//                 }
//                 if (result[0] == "" || result[1] == "") {
//                     if (result[0] != "") {
//                         str.append(result[0]);
//                         str.append(" with unknown last name");
                        
//                     } else if (result[1] != "") {
//                         str.append(result[1]);
//                         str.append(" with unknown first name");
//                     }
//                 }
//                 else {
//                     str.append(result[0]);
//                     str.append(" ");
//                     str.append(result[1]);
//                 }
//                 return str;
//             }
//         }
//         return str;
//     } else {
//         // cout << "Incognito";// << endl;
//         return incognito;
//     }
//   }
// private:
//   // приватные поля
//   map<int, vector<string>> person_data; 
// };


void TestSomething() {

    Person person;
    person.ChangeLastName(1967, "Sergeeva");
    AssertEqual(person.GetFullName(1968), "Sergeeva with unknown first name");
    person.ChangeFirstName(1965, "Polina");

    AssertEqual(person.GetFullName(1900), "Incognito");
    AssertEqual("Polina with unknown last name", person.GetFullName(1965));
    AssertEqual("Polina Sergeeva", person.GetFullName(1990));

    person.ChangeFirstName(1970, "Appolinaria");
    AssertEqual("Polina Sergeeva", person.GetFullName(1969));
    AssertEqual("Appolinaria Sergeeva", person.GetFullName(1970));

    person.ChangeLastName(1968, "Volkova");
    AssertEqual("Polina Volkova", person.GetFullName(1969));
    AssertEqual("Appolinaria Volkova", person.GetFullName(1970));

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
