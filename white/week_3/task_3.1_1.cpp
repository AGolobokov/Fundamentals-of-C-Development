#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> array;
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
      int num;
      cin >> num;
      array.push_back(num);
  }
  sort(begin(array), end(array), [](int a, int b){return abs(a) < abs(b);});
  for (auto x : array) {
      cout << x << ' ';
  }
  return 0;
}