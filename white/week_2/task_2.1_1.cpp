#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Factorial(int n) {
    int result = 1;
    if (n >= 0) {
        for (int i = 1; i <= n;i++) {
            result *=i;
        }

    } else {
        return 1;
    }
    return result;
};

int main()
{
  int N;
  
  cin >> N;
  cout <<  Factorial(N);

  return 0;
}