#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    string line;
    ofstream out("output.txt");
    ifstream in("input.txt"); 
    if (in.is_open()) {
        while (getline(in, line)) {
            out << line << endl;
        }
    }
    in.close(); 
    out.close();  

  return 0;
}