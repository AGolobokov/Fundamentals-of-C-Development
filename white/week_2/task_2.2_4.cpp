#include <algorithm>
using namespace std;


vector<int> Reversed(const vector<int>& v) {
    vector<int> result;
    for (auto & item :v) {
        result.push_back(item);
    }
    reverse(result.begin(), result.end());
    return result;
}