#include <iostream>

using namespace std;

int main()
{   
    double N, A, B, X, Y;//150 110 120 5 12.5
    
    cin >> N >> A >> B >> X >> Y;

    if (N > B) {
        cout << N * ((100 - Y)/100);
    }
    else if (N > A) {
        cout << N * ((100 - X)/100);
    }
    else {
        cout << N;
    }

    return 0;
}