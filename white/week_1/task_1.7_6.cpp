#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> result;
  int N;

  cin >> N;
  while (N != 0) {
    if (N % 2 == 0) {
      result.push_back(0);
    }
    else {
      result.push_back(1);
    }
    N = N / 2;
  }

  reverse(result.begin(), result.end());

  for (int i = 0; i < result.size(); i++) {
    cout << result[i];
  }
}