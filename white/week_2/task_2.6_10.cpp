#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <iterator>
#include <vector>


using namespace std;

int main()
{
  int Q = 0;
  set<set<string>> set_route;
  vector<set<string>> v_bus_order;  
  cin >> Q;
  static int counter = 1;
  for (int i = 0; i < Q; i++) {
    int num = 0;
    cin >> num;

    set<string> local_set;

    for (int j = 0; j < num; j++) {
      string stop;
      cin >> stop;
      local_set.insert(stop);
    }

    int tmp_size_1 = set_route.size();
    set_route.insert(local_set);
    int tmp_size_2 = set_route.size();

    if (tmp_size_2 > tmp_size_1) {
      v_bus_order.push_back(local_set);
      cout << "New bus " << counter << endl;
      counter++;
    } else {
      for (int j = 0; j < v_bus_order.size(); j++) {
        if (v_bus_order[j] == local_set) {
          cout << "Already exists for " << j+1 << endl;
        }
      }
    }
  }

  return 0;
}
