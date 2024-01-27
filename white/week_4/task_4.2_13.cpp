#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

std::vector<std::string> split(std::string & s, char delimeter)
{
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> tokens;
    while (std::getline(ss, item, delimeter))
    {
       tokens.push_back(item);
    }
    return tokens;
}

int main()
{
    int N = 0;
    int M = 0;
    string line;
    vector<vector<string>> matrix;
    
    ifstream in("input.txt");
    int one_time = 0;
    int t_c = 0; 
    if (in.is_open()) {
        while (getline(in, line)) {
            if (one_time == 0) {
                vector<std::string> tokens = split(line, ' ');
                N = stoi(tokens[0]);
                M = stoi(tokens[1]);
                one_time++;
            } else {
                vector<std::string> tokens = split(line, ',');
                matrix.push_back(tokens);
            }
        }
    }
    in.close(); 
    int num = 0;
    int mun = 0;
    for(auto x: matrix) {
        for (auto y: x) {
            cout<< fixed;
            num++;
            cout << setw(10) << y;
            if (num < M) {
                cout << " ";  
            }
        }
        if (num == M) {
            mun++;
            if (mun != N) {
                cout << endl; 
            }  
            num = 0;
        }
    } 

  return 0;
}