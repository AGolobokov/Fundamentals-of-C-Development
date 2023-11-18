#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <map>


using namespace std;

int main()
{
  vector<string> array;
  map<vector<char>, string> m1;

  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
      string str;
      cin >> str;
      array.push_back(str);
  }
  
  for (auto &x : array) {
      vector <char> temp_v;
      for (auto &y : x) {
          temp_v.push_back(tolower(y));
      }
      
      m1[temp_v] = x;
  }
      
  for (auto [first, second] : m1) {
      cout << second << " ";
      
  }
  return 0;
}