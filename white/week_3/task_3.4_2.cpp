#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;


class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
    vector<string> v(2);
    if (person_data.count(year) != 0) {
        for (const auto &item: person_data) {
            if (item.first == year) {
                v[1] = item.second[1];
                break;
            }
        }
    }
    v[0] = first_name;
    person_data[year] = v;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    vector<string> v(2);
    if (person_data.count(year) != 0) {
        for (const auto &item: person_data) {
            if (item.first == year) {
                v[0] = item.second[0];
                break;
            }
        }
    }
    v[1] = last_name;
    person_data[year] = v;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года 
    if (person_data.size() != 0) {
        string str = "";
        vector<string> result(2);
        map<int, vector<string>> reserv; 
        if (person_data.count(year) != 0) {
            for (const auto &item : person_data) {
                if (item.first == year) {
                    if (item.second[0] != "") {
                        result[0] = item.second[0];
                    }
                    if (item.second[1] != "") {
                        result[1] = item.second[1];
                    }
                    break;
                } else {
                    if (item.second[0] != "") {
                        result[0] = item.second[0];
                    }
                    if (item.second[1] != "") {
                        result[1] = item.second[1];
                    }
                }
            }
            
            if (result[0] == "" || result[1] == "") {
                if (result[0] != "") {
                    str.append(result[0]);
                    str.append(" with unknown last name");
                    
                } else if (result[1] != "") {
                    str.append(result[1]);
                    str.append(" with unknown first name");
                }
            } else {
                str.append(result[0]);
                str.append(" ");
                str.append(result[1]);
            }
        }
        else {
            vector<int> years;
            for (const auto &item : person_data) {
                years.push_back(item.first);
            }
            if (year < years[0]) {
                cout << "Incognito";// << endl;
            } else {
                for (const auto &item : person_data) {
                    if (item.first < year) {
                        if (item.second[0] != "") {
                            result[0] = item.second[0];
                        }
                        if (item.second[1] != "") {
                            result[1] = item.second[1];
                        }
                    } else {
                        break;

                    }
                
                }
                if (result[0] == "" || result[1] == "") {
                    if (result[0] != "") {
                        str.append(result[0]);
                        str.append(" with unknown last name");
                        
                    } else if (result[1] != "") {
                        str.append(result[1]);
                        str.append(" with unknown first name");
                    }
                }
                else {
                    str.append(result[0]);
                    str.append(" ");
                    str.append(result[1]);
                }
                return str;
            }
        }
        return str;
    } else {
        cout << "Incognito";// << endl;
    }
  }
private:
  // приватные поля
  map<int, vector<string>> person_data; 
};
int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}