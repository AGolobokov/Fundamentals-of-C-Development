#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  if (range_begin + 1 != range_end) {
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    MergeSort(elements.begin(), elements.begin() + elements.size()/2); 
    MergeSort(elements.begin() + elements.size()/2, elements.end());
    merge(elements.begin(), elements.begin() + elements.size()/2, elements.begin() + elements.size()/2, elements.end(), range_begin);
  }
}

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5, 3, 1, 0};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}