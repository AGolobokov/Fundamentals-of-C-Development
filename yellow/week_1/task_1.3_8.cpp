#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main()
{
  int32_t N = 0;
  vector<int64_t> v;  
  cin >> N;
  int64_t sum = 0;
  for (int i = 0; i < N; i++) {
      int num = 0;
      cin >> num;
      sum += num;
      v.push_back(num);
  }

  int64_t av_t = sum/N;
  int count = 0;
  vector<int> result;
  for (int32_t i = 0;i < v.size(); i++) {
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