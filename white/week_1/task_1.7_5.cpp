#include <iostream>

using namespace std;

int a, b;

int main()
{
    cin >> a >> b;

    if(a == 0) {
        cout << b;
    }
    else if (b == 0) {
        cout << a;
    }
    else {
        while(a > 0 && b > 0) {
            a > b ? a = a % b : b = b % a;
        }
        cout << a + b;
    }
    return 0;
}