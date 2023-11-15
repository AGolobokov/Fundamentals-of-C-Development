#include <iostream>
#include <algorithm>

using namespace std;

int main()
{   
    string a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    cout << std::min(std::min(a,b),c);

    return 0;
}