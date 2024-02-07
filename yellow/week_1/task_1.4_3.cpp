#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> 
#include <iterator>
#include <tuple>


using namespace std;

// enum class Lang {
//   DE, FR, IT
// };

// struct Region {
//   string std_name;
//   string parent_std_name;
//   map<Lang, string> names;
//   int64_t population;
// };



int FindMaxRepetitionCount(const vector<Region>& regions) {
    int result = 0;
    map<tuple <string, string, map<Lang, string>, int64_t>, int> my_map;
    for (auto element : regions)  {
        tuple <string, string, map<Lang, string>, int64_t> tuple_element(element.std_name, element.parent_std_name, element.names, element.population);
        my_map[tuple_element] += 1;
        if (my_map[tuple_element] > result) {
            result = my_map[tuple_element];
        }
    }
    return result;
};

// int main() {
//   cout << FindMaxRepetitionCount({
//       {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Russia",
//           "Eurasia",
//           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//           89
//       }, {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Russia",
//           "Eurasia",
//           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//           89
//       },
//   }) << endl;
  
//   cout << FindMaxRepetitionCount({
//       {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Russia",
//           "Eurasia",
//           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//           89
//       }, {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Moscow",
//           "Toulouse",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           31
//       },
//   }) << endl;
  
//   return 0;
// }