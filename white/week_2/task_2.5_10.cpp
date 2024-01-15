#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>


using namespace std;

int main()
{
  int Q = 0;
  
  map <string, vector<string>> route;// bus , route
  map <int, string> route_order;// bus num order , bus name
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    string command;
    cin >> command;
    if (command == "NEW_BUS") {
        static int counter = 0;
        string bus_name;
        cin >> bus_name;
        route_order[counter] = bus_name;
        counter++;
        int stop_count;
        cin >> stop_count;
        vector<string> bus_stops;
        for (int j = 0; j < stop_count; j++) {
            string stop_name;
            cin >> stop_name;
            bus_stops.push_back(stop_name);
        }
        route[bus_name] = bus_stops; 
    } else if (command == "BUSES_FOR_STOP") {
        string stop_name;
        cin >> stop_name;
        int counter = 0;
        for (auto x : route_order) {
            for (auto y: route[x.second]) {
                if (y == stop_name) {
                    cout << x.second << " ";
                    counter++;
                }
            }
        }
        if (!counter)  {
            cout << "No stop";
        }
        cout << endl;
    } else if (command == "STOPS_FOR_BUS") {
        string bus_name;
        cin >> bus_name;
        if (route.count(bus_name) == 1) {
            for (auto x : route[bus_name]) {
                cout << "Stop " << x << ": ";
                int counter = 0;
                for (auto sp : route_order) {
                    for (auto y: route[sp.second]) {
                        if (y == x && sp.second != bus_name) {
                            cout << sp.second << " ";
                            counter++;
                        }
                    }
                }
                if (!counter) {
                    cout << "no interchange";
                }
                cout << endl;
            }
        } else  {
            cout << "No bus" << endl;
        }
    } else if (command == "ALL_BUSES") {
        if (route.empty()) {
            cout << "No buses";
        } else {
            for (auto r : route) {
                cout << "Bus "<< r.first << ": ";
                for (auto station : r.second) {
                    cout <<  station << " ";
                }
            }
        }
        cout << endl;
    }
  }

  return 0;
}
