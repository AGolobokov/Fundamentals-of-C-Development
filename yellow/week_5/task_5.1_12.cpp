#include <iostream>

using namespace std;

class Animal {
public:
    // ваш код
    Animal(string _Name) : Name(_Name) {}
    const string Name;
};


class Dog: public Animal 
{
public:
    // ваш код
    Dog(string _name) : Animal(_name) {}

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};