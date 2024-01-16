#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <iterator>


using namespace std;

int main()
{
  int Q = 0;
  set<set<string>> set_string; 
  map<string, int> dict;  
  cin >> Q;
  for (int i = 0; i < Q; i++) {
      string command;
      cin >> command;
      if (command == "ADD") {
          string first_w, second_w;
          cin >> first_w;
          cin >> second_w;
          int f_size = set_string.size();
          set<string> set_string_local;

          set_string_local.insert(first_w);
          set_string_local.insert(second_w);
          set_string.insert(set_string_local);
          int s_size = set_string.size();
          if (f_size != s_size) {
            dict[first_w] += 1;
            dict[second_w] += 1;
          }
      } else if (command == "COUNT") {
          string check_w;
          cin >> check_w;
          int find = 0;
          if (dict.count(check_w) != 0) {
            find = dict[check_w];
          }
          else {
            find = 0;
          }
          cout << find << endl;
      } else if (command == "CHECK") {
          string check_first_w, check_second_w;
          cin >> check_first_w;
          cin >> check_second_w;
          bool find = false;
          set<string> set_string_local_check;
          set_string_local_check.insert(check_first_w);
          set_string_local_check.insert(check_second_w);
          if (set_string.find(set_string_local_check) != set_string.end()) {
              find = true;
          }
          if (find) {
            cout << "YES" << endl;
          } else {
            cout << "NO" << endl;
          }
      }
  }

  return 0;
}
