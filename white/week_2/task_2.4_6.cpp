#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main()
{
  int N = 0;
  vector<int> v;  
  cin >> N;

  for (int i = 0; i < N; i++) {
    string str;
    int index;
    cin >> str;
    
    if (str == "COME") {
      cin >> index;
      if (index > 0) {
        for (int i = 0; i < index; i++) {
          v.push_back(0);
        }
      } else if (index < 0) {
        index = -index;
        for (int i = 0; i < index; i++) {
          v.erase(v.end() - 1);
        }
      }
    }
    else if (str == "WORRY") {
      cin >> index;
      v[index] = 1;
    } 
    else if (str == "QUIET") {
      cin >> index;
      v[index] = 0;
    } 

    if (str == "WORRY_COUNT") {
      int res = 0;
      for (auto x:v) {
        if (x) {
          res++;
        }
      }
      cout << res << endl;
    }
  }

  return 0;
}
