#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class Person {
    public:
    Person(string pname = "person") : Name(pname) {}
    virtual void Walk(string destination) const = 0;
    string Name;
};


class Student : public Person {
public:

    Student(string name, string favouriteSong) : Person(name) {
        Name = name;
        FavouriteSong = favouriteSong;
    } 

    void Learn() {
        cout << "Student: " << Name << " learns" << endl;
    }

    void Walk(string destination) const  override {
        cout << "Student: " << Name << " walks to: " << destination << endl;
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() {
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

public:
    string Name;
    string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(string name, string subject) : Person(name) {
        Name = name;
        Subject = subject;
    } 

    void Teach() {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }

    void Walk(string destination) const override {
        cout << "Teacher: " << Name << " walks to: " << destination << endl;
    }

public:
    string Name;
    string Subject;
};


class Policeman : public Person {
public:
    Policeman(string name) : Person(name)  {
        Name = name;
    }
    
    void Check(Person & p) {
        if (typeid(p).name() == typeid(Teacher).name()) {
            cout << "Policeman: " << Name << " checks Teacher. Teacher's name is: " << p.Name << endl;
        } else if (typeid(p).name() == typeid(Student).name()) {
            cout << "Policeman: " << Name << " checks Student. Student's name is: " << p.Name << endl;
        } else if (typeid(p).name() == typeid(Policeman).name()) {
            cout << "Policeman: " << Name << " checks Policeman. Policeman's name is: " << p.Name << endl;
        }
    }

    void Walk(string destination) const override {
        cout << "Policeman: " << Name << " walks to: " << destination << endl;
    }

public:
    string Name;
};


template <typename T>
void VisitPlaces(T man, vector<string> places) {
    for (auto p : places) {
        man.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}