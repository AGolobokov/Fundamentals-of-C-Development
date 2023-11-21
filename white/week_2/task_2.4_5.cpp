#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main()
{
  int N = 0;
  vector<int> v;  
  cin >> N;
  int sum = 0;
  for (int i = 0; i < N; i++) {
      int num = 0;
      cin >> num;
      sum += num;
      v.push_back(num);
  }

  int av_t = sum/N;
  int count = 0;
  vector<int> result;
  for (int i = 0;i < v.size(); i++) {
      if (v[i] > av_t) {
          count++;
          result.push_back(i);
      }
  }
  cout << count << endl;
    for (auto x : result) {
        cout << x << ' ';
    }
  return 0;
}