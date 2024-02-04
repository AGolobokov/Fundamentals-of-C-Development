#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

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
    int64_t N = 0;
    uint64_t dencity = 0;
    string line;

    uint64_t result  = 0;
    int t_c = 0; 
    getline(cin, line);
    vector<std::string> first_tokens = split(line, ' ');
    N = stoi(first_tokens[0]);
    dencity = stoi(first_tokens[1]);
    for (int i = 0; i < N; i++) {
        string data;
        getline(cin, data);
        vector<std::string> whd = split(data, ' ');
        int64_t W = stoi(whd[0]);
        int64_t H = stoi(whd[1]);
        int64_t D = stoi(whd[2]);
        result+= (W*H*D*dencity);
    }
    cout << result << endl;
    return 0;
}
