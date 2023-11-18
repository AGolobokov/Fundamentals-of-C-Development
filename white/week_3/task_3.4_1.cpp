#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


class SortedStrings {
public:
  void AddString(const string& s) {
    // добавить строку s в набор
    storage_strings.push_back(s);
  }
  vector<string> GetSortedStrings() {
    // получить набор из всех добавленных строк в отсортированном порядке
    
    sort(begin(storage_strings), end(storage_strings),[](string a, string b){return a < b;});
    return storage_strings;
  }
private:
  // приватные поля
  vector<string> storage_strings;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;
  
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  return 0;
}