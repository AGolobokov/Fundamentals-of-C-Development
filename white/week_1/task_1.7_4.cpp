#include <iostream>

using namespace std;

int main()
{   
    string str;
    cin >> str;

    int counter = 0;
    int index = 0;

    for (auto x : str) {
        index++;
        if (x == 'f') {
           counter += 1;
           if (counter == 2) {
             cout << index-1;
             return 0;
           } 
        } 
    }

    if (!counter) {
        cout << -2;
    }
    else if (counter == 1) {
        cout << -1;
    }

    return 0;
}