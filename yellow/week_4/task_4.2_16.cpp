#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  if (range_begin + 1 != range_end) {
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    MergeSort(elements.begin(), elements.begin() + elements.size()/3); 
    MergeSort(elements.begin() + elements.size()/3, elements.begin() + elements.size()/3 + elements.size()/3);
    vector<typename RandomIt::value_type> tmp;
    merge(elements.begin(), elements.begin() + elements.size()/3, elements.begin() + elements.size()/3, elements.begin() + elements.size()/3 + elements.size()/3, back_inserter(tmp));
    MergeSort(elements.begin() + elements.size()/3 + elements.size()/3, elements.end());
    merge(tmp.begin(), tmp.end(), elements.begin() + elements.size()/3 + elements.size()/3, elements.end(), range_begin);
  }
}

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}