#include <iostream>
#include <map>
#include <algorithm>
#include <string>


using namespace std;


int main()
{
  int N = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
      string key, valye;
      cin >> key >> valye;
      map<char, int> m1, m2;
      for (auto x : key) {
          if (m1.count(char(x))) {
              m1[char(x)] += 1;
          }
          else {
              m1[char(x)] = 1;
          }
      }
      for (auto x : valye) {
          if (m2.count(char(x))) {
              m2[char(x)] += 1;
          }
          else {
              m2[char(x)] = 1;
          }
      }
      if (m1 == m2) {
          cout << "YES" << endl;
      }
      else {
        cout << "NO" << endl;
      }
  }

  return 0;
}
