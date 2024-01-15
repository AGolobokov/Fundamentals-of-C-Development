#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <set>


using namespace std;

int main()
{
  int Q = 0;
  
  set <map<vector<string>, int>> route;// num  , route
  map<int, vector<string>> order;
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int stop_number = 0; 
    cin >> stop_number;
    
    vector<string> stops_name;
    map<vector<string>, int> inside;
    for (int j = 0; j < stop_number; j++) {
        string new_stop;
        cin >> new_stop;
        stops_name.push_back(new_stop);
    }
    inside[stops_name] = stop_number;

    if (route.count(inside) == 1) {
        for (auto x : order) {
            if (x.second == stops_name) {
                cout << "Already exists for " << x.first << endl;
            }
        }
    } else {
        static int res = 1;
        route.insert(inside);
        order[res] = stops_name;
        cout << "New bus " << res << endl;
        res++;
    }
  }

  return 0;
}
