#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;


class ReversibleString {
public:
    ReversibleString(){};
    
    ReversibleString(const string &str) { 
       internal_str = str;
    };

    void Reverse() {
        reverse(internal_str.begin(), internal_str.end());
    };
    string ToString() const { 
        return internal_str;

    };
private:
    string internal_str;
};


int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
   s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
   ReversibleString empty;
   cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}