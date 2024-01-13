#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// void PrintVectorPart(const vector<int>& numbers);

void PrintVectorPart(const vector<int>& numbers) {
    vector <int> tmp;
    for (const auto x : numbers) {
        if (x < 0) {
            break;
        }
        tmp.push_back(x);
    }
    auto it = end(tmp);
    while (it != begin(tmp)) {
        it--;
        cout << *it << " ";
    }
    
}

// int main() {
//   PrintVectorPart({6, 1, 8, -5, 4});
//   cout << endl;
//   PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
//   cout << endl;
//   PrintVectorPart({6, 1, 8, 5, 4});
//   cout << endl;
//   return 0;
// }