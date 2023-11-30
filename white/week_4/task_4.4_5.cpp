#include <string>
#include <sstream>
#include <iostream>
#include <exception>
#include <iomanip>


using namespace std;

void EnsureEqual(const string& left, const string& right) {

    if (left != right) {
        stringstream ss;
        ss << left << " != " << right;
        throw runtime_error(ss.str());
    }
}