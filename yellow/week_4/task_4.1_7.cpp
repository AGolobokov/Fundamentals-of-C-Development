#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>



using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> result;
    int s_size = s.length();
    int end_find = 0;
    vector<char> word;
    for (auto sign : s) {
        end_find++;
        if (sign != ' ') {
            word.push_back(sign);
        }
        if (sign == ' ' || end_find == s_size) {
            string str(word.begin(), word.end()); 
            result.push_back(str);
            word.clear();
        }
    }
    return result;
}


// int main() {
//   string s = "C Cpp Java Python";

//   vector<string> words = SplitIntoWords(s);
//   cout << words.size() << " ";
//   for (auto it = begin(words); it != end(words); ++it) {
//     if (it != begin(words)) {
//       cout << "/";
//     }
//     cout << *it;
//   }
//   cout << endl;
  
//   return 0;
// }