#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end, char prefix) {
    RandomIt first = lower_bound(range_begin, range_end, string({prefix}));
    RandomIt second = lower_bound(range_begin, range_end, string({static_cast<char>(static_cast<int>(prefix) + 1)}));
    return make_pair(first, second);
}



int main() {
  const vector<string> sorted_strings = {"moscow", "murmansk", "vologda", "vologdaa"};
  
  const auto m_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'v');
  for (auto it = m_result.first; it != m_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  
  const auto p_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
  cout << (p_result.first - begin(sorted_strings)) << " " <<
      (p_result.second - begin(sorted_strings)) << endl;
  
  const auto z_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
  cout << (z_result.first - begin(sorted_strings)) << " " <<
      (z_result.second - begin(sorted_strings)) << endl;
  
  return 0;
}

