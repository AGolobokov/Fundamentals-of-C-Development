#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


// enum class Gender {
//   FEMALE,
//   MALE
// };

// struct Person {
//   int age;  // возраст
//   Gender gender;  // пол
//   bool is_employed;  // имеет ли работу
// };



// // Это пример функции, его не нужно отправлять вместе с функцией PrintStats
// template <typename InputIt>
// int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
//   if (range_begin == range_end) {
//     return 0;
//   }
//   vector<typename InputIt::value_type> range_copy(range_begin, range_end);
//   auto middle = begin(range_copy) + range_copy.size() / 2;
//   nth_element(
//       begin(range_copy), middle, end(range_copy),
//       [](const Person& lhs, const Person& rhs) {
//         return lhs.age < rhs.age;
//       }
//   );
//   return middle->age;
// }

void PrintStats(vector<Person> persons) {
    cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << endl;
    vector<Person> persons_females;
    auto it = std::partition(persons.begin(), persons.end(), [](Person i) {return i.gender == Gender::FEMALE;});
    cout << "Median age for females = " << ComputeMedianAge(begin(persons), it) << endl;
    auto it1 = std::partition(persons.begin(), persons.end(), [](Person i) {return i.gender == Gender::MALE;});
    cout << "Median age for males = " << ComputeMedianAge(begin(persons), it1) << endl;
    auto it2 = std::partition(persons.begin(), persons.end(), [](Person i) {return (i.gender == Gender::FEMALE && i.is_employed == true);});
    cout << "Median age for employed females = " << ComputeMedianAge(begin(persons), it2) << endl;
    auto it3 = std::partition(persons.begin(), persons.end(), [](Person i) {return (i.gender == Gender::FEMALE && i.is_employed == false);});
    cout << "Median age for unemployed females = " << ComputeMedianAge(begin(persons), it3) << endl;
    auto it4 = std::partition(persons.begin(), persons.end(), [](Person i) {return (i.gender == Gender::MALE && i.is_employed == true);});
    cout << "Median age for employed males = " << ComputeMedianAge(begin(persons), it4) << endl;
    auto it5 = std::partition(persons.begin(), persons.end(), [](Person i) {return (i.gender == Gender::MALE && i.is_employed == false);});
    cout << "Median age for unemployed males = " << ComputeMedianAge(begin(persons), it5) << endl;
}

// int main() {
//   vector<Person> persons = {
//       {31, Gender::MALE, false},
//       {40, Gender::FEMALE, true},
//       {24, Gender::MALE, true},
//       {20, Gender::FEMALE, true},
//       {80, Gender::FEMALE, false},
//       {78, Gender::MALE, false},
//       {10, Gender::FEMALE, false},
//       {55, Gender::MALE, true},
//   };
//   PrintStats(persons);
//   return 0;
// }