#include <iostream>
#include <vector>

using namespace std;


class Incognizable {
public:
    Incognizable(){};
    Incognizable(int a){
        inside_1 = a;
    };
    Incognizable(int a, int b){
        inside_1 = a;
        inside_2 = b;
    };
private:
    int inside_1, inside_2;
    vector <int> v;    
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}