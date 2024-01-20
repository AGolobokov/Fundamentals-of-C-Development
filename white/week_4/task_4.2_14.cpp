#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Date {
 int day;
 int month;
 int year;
};

struct Student {
    string name;
    string surname;
    Date date;
};

int main()
{
    vector<Student> vstudent;
    int Q = 0;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        Student current_student;
        cin >> current_student.name;
        cin >> current_student.surname;
        cin >> current_student.date.day;
        cin >> current_student.date.month;
        cin >> current_student.date.year;
        vstudent.push_back(current_student);
    }
    int M = 0;
    cin >> M;
    for (int i = 0; i < M; i++) {
        string command;
        cin >> command;
        int num = 0;
        cin >> num; 
        if ((num-1) > Q || num <= 0 ) {
            cout << "bad request" << endl;
        }
        else if (command == "name") {
            string name = vstudent[num-1].name;
            string surname = vstudent[num-1].surname;
            cout << name << " ";
            cout << surname << endl;
        } else if (command == "date") {
            int d = vstudent[num-1].date.day;
            int m = vstudent[num-1].date.month;
            int y = vstudent[num-1].date.year; 
            cout << d << "."; 
            cout << m << "."; 
            cout << y << endl; 
        }
        else if (command != "name" && command != "date") {
            cout << "bad request" << endl;
        }
    }

  return 0;
}