#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;


set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
    auto r =  abs(*(numbers.begin()) - border);
    auto it_result = numbers.begin();
    for (auto it = numbers.begin(); it != numbers.end(); it++) {
      if (abs(*it-border) < r) {
        it_result = it; 
        r = abs(*it-border);
      } 
    }
    return it_result;
}
// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел

int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;
      
  set<int> empty_set;
  
  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
