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
    string GetFullNameWithHistory(int year) {
        string answer_result = "";
        string first_time = "";

        first_time = GetFullName(year);
        if (first_time == "Incognito") {
            return first_time;
        }
        else {
            vector <string> res_name;
            vector <string> res_surname;
            string gfh_name = "";
            string gfh_surname = "";
            int name_get = 0;
            int surname_get = 0;
            auto map_it  = person_data.begin();
            if (map_it->first <= year) {
                for (auto it = person_data.rbegin(); it != person_data.rend(); ++it) {
                    if (it->first <= year) {
                        if (it->second[0] != "") {
                            if (gfh_name != it->second[0]) {
                                gfh_name = it->second[0];
                                res_name.push_back(gfh_name);
                            }
                        }
                        if (it->second[1] != "") {
                            if (gfh_surname != it->second[1]) {
                                gfh_surname = it->second[1];
                                res_surname.push_back(gfh_surname);
                            }
                        }
                    }
                }
                int size_res_name = res_name.size();
                int size_res_surname = res_surname.size();

                if (size_res_name == 1) {
                    answer_result += res_name[0] + " ";
                } else if (size_res_name == 2) {
                    answer_result += res_name[0] + " (" + res_name[1] + ") ";
                } else if (size_res_name > 2) {
                    for (int i = 0;i < size_res_name; i++) {
                        if (i == 0) {
                            answer_result += res_name[i] + " ";
                        } else if (i == 1) {
                            answer_result += "(" + res_name[i] + ", ";
                        } else if (i == (size_res_name - 1)) {
                            answer_result += res_name[i] + ") ";
                        } else if (i > 1) {
                            answer_result += res_name[i] + ", ";
                        }
                    }
                }

                if (size_res_surname == 1) {
                    answer_result += res_surname[0];
                } else if (size_res_surname == 2) {
                    answer_result += res_surname[0] + " (" + res_surname[1] + ")";
                } else if (size_res_surname > 2) {
                    for (int i = 0;i < size_res_surname; i++) {
                        if (i == 0) {
                            answer_result += res_surname[i] + " ";
                        } else if (i == 1) {
                            answer_result += "(" + res_surname[i] + ", ";
                        } else if (i == (size_res_surname - 1)) {
                            answer_result += res_surname[i] + ")";
                        } else if (i > 1) {
                            answer_result += res_surname[i] + ", ";
                        }
                    }
                }
                if (res_surname.size() == 0) {
                    answer_result += "with unknown last name";
                }
                else if (res_name.size() == 0) {
                    answer_result += " with unknown first name";
                }
            } 

            return answer_result;
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
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  cout << person.GetFullNameWithHistory(1900) << endl;

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}