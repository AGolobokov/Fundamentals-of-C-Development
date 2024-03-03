#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
 
using namespace std;
 
int Q = 0;

int main() {
  vector<int> vec;
  cin >> Q;

  for (int i = Q; i > 0; i--) {
    vec.push_back(i);
  }

  do
  {
    for (auto x: vec) {
      cout << x << " ";
    }
    cout << endl;
  }
  while(prev_permutation(vec.begin(), vec.end()));

  return 0;
}