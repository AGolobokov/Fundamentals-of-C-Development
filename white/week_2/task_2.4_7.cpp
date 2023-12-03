#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

vector<int> DAYS_IN_MONTH = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
  int Q = 0;
  vector<vector<string>> v; 
  v.resize(DAYS_IN_MONTH[0]);
  cin >> Q;
  int month_counter = 0;

  for (int i = 0; i < Q; i++) {
    string str;
    int day_num;
    cin >> str;
    
    if (str == "ADD") {
        cin >> day_num;
        string work;
        cin >> work;
        vector<string> vec;
        vec.push_back(work);
        if (v[day_num - 1].empty()) {
            v[day_num - 1].push_back(work);
        }
        else {
            v[day_num - 1].push_back(work);
        }
    }
    else if (str == "DUMP") {
      cin >> day_num;
      int val = v[day_num - 1].size();
      cout << val << " ";
      for (int i = 0; i < val; i++) {
        cout << v[day_num - 1][i] << " ";
      }
      cout << endl;
    } 
    else if (str == "NEXT") {
        month_counter++;
        uint8_t step = 0;
        if (month_counter > 11) {
            month_counter = 0;
        } 

        if (DAYS_IN_MONTH[month_counter] > DAYS_IN_MONTH[month_counter - 1]) {
            v.resize(DAYS_IN_MONTH[month_counter]);
        }
        else if (DAYS_IN_MONTH[month_counter] < DAYS_IN_MONTH[month_counter - 1]) {
            int diff_day = DAYS_IN_MONTH[month_counter - 1] - DAYS_IN_MONTH[month_counter];//3
            for (diff_day; diff_day > 0; diff_day--) {
                for (auto i : v[DAYS_IN_MONTH[month_counter] + diff_day - 1]) {
                    v[DAYS_IN_MONTH[month_counter] - 1].push_back(i);
                }
            }
            v.resize(DAYS_IN_MONTH[month_counter]);
        }
    } 
  }

  return 0;
}
