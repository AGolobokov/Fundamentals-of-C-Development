#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
    string line;
 
    ifstream in("input.txt"); 
    if (in.is_open()) {
        while (getline(in, line)) {
            double x = stod(line);
            cout<< fixed << setprecision(3);
            cout << x << endl;
        }
    }
    in.close();   

  return 0;
}