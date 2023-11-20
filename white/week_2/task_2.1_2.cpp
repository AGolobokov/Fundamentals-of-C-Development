#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool IsPalindrom(string str) {
    string str_copy = str;
    if (str.size() == 1 || str.size() == 0) {
        return true;
    }
    else if (str.size() > 1) {
        for (int i = 0; i <= str.size()/2 - 1; i++) {

            if (str[i] != str[str.size()-1 - i]) {
                return false;
            }
        }
        return true;
        
    }
    return false;
};

int main()
{
  string str;
  
  cin >> str;
  cout <<  IsPalindrom(str);

  return 0;
}