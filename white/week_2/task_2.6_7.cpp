#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
  int N = 0;
  set<string> set_string;  
  cin >> N;
  for (int i = 0; i < N; i++) {
      string str;
      cin >> str;
      set_string.insert(str);
  }
  cout << set_string.size();

  return 0;
}