#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> 
#include <iterator>
#include <stdexcept> 

using namespace std;

template<typename T1, typename T2> 
T2 & GetRefStrict(map<T1, T2> & m, T1 a) {
    if ( m.count(a) == 0) {
        throw runtime_error("hint");
    } else {
        return m[a];
    }
}

int main() {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 1);
    // cout << item << endl;
    item = "newvalue";
    cout << m[0] << endl;

    return 0;
}