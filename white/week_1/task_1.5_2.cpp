#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{   
    // Ax² + Bx + C = 0.
    double a, b, c, D;

    cin >> a;
    cin >> b;
    cin >> c;

    if (a == 0 && b == 0) {

    }
    else if (a == 0 && b != 0) {
        cout << -c/b;
    }
    else {
        D = (b * b) - (4 * a * c);
        if (D == 0) {
            cout << (-b / (2 * a));
        }
        else if (D > 0 ) {
            cout << (-b + sqrt(D)) / (2 * a) << ' ' << (-b - sqrt(D)) / (2 * a);
        }
    }

    return 0;
}