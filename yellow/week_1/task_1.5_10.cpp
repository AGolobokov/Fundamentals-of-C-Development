#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

template<typename T>
vector<T> operator*(vector<T> &vec1, vector<T> &vec2);

template<typename T1, typename T2>
pair<T1,T2> operator*(pair<T1,T2> &p1, pair<T1,T2> &p2);

template<typename T1, typename T2>
map<T1,T2> operator*(map<T1,T2> &m1, map<T1,T2> &m2);

template<typename T>
vector<T> operator*(vector<T> &vec1, vector<T> &vec2) {
    vector<T> vec3;
    for (uint8_t i = 0; i < vec1.size(); i++) {
        vec3.push_back(vec1[i] * vec2[i]);
    }
    return vec3;
}



template<typename T1, typename T2>
pair<T1,T2> operator*(pair<T1,T2> &p1, pair<T1,T2> &p2) {
    T1 x1 = p1.first * p2.first;
    T2 x2 = p1.second * p2.second;
    return make_pair(x1, x2);
}



template<typename T1, typename T2>
map<T1,T2> operator*(map<T1,T2> &m1, map<T1,T2> &m2) {
    map<T1,T2> m3;
    for (auto x : m1) {
        m3[x.first] = x.second * m2[x.first];
    }
    return m3;
}

template<typename T> 
T Sqr(T x) {
    return x * x;
}

int main() {
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
    cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
    {4, {2, 2}},
    {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}