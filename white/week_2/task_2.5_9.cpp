#include <iostream>
#include <map>
#include <algorithm>
#include <string>


using namespace std;


int main()
{
  int N = 0;
  map <string, string> dict;// country , capital
  cin >> N;
  for (int i = 0; i < N; i++) {
    string command;
    int day_num;
    cin >> command;
    if (command == "CHANGE_CAPITAL") {
        string country;
        string capital;
        cin >> country;
        cin >> capital;
        if (dict.count(country) == 1) {
            for (auto [key, value] : dict) {
                if (dict[country] == capital) {
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                    break;
                } else {
                    cout << "Country " << country << " has changed its capital from " << dict[country] << " to " << capital << endl;
                    dict[country] = capital;
                    break;
                }
            }
        } else if (dict.count(country) == 0) {
            dict[country] = capital;
            cout << "Introduce new country " << country << " with capital "<< capital << endl;
        }
    } else if (command == "RENAME" ) {
        string capital;
        string old_country;
        cin >> old_country;
        string new_country;
        cin >> new_country;
        if (old_country == new_country || dict.count(old_country) == 0 || dict.count(new_country) == 1) {
            cout << "Incorrect rename, skip" << endl;
        } else {
            capital = dict[old_country];
            dict.erase(old_country);
            dict[new_country] = capital;
            cout << "Country  "<< old_country <<" with capital "<<capital<<" has been renamed to " <<new_country<< endl;
        }
    } else if (command == "ABOUT" ) {
        string country;
        cin >> country;

        if (dict.count(country) == 1) {
            cout << "Country " << country << " has capital " <<  dict[country] << endl; 
        }
        else {
            cout << "Country " <<  country << " doesn't exist" << endl;
        }

    } else if (command == "DUMP" ) {
        if (dict.empty()) {
            cout << "There are no countries in the world" << endl;
        }
        else {
            for (auto& [key, value] : dict) {
                cout << key << "/" << value << " ";
            }
        }
    }
  }

  return 0;
}
