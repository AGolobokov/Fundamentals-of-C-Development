#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

 struct Specialization {
     string specialization_name;
     
     explicit Specialization(string new_str) {
         specialization_name = new_str;
     };
 };

 struct Course {
     string course_name;
     explicit Course(string new_str) {
         course_name = new_str;
     };
 }; 
 
 struct Week {
     string week_name;
     explicit Week(string new_str) {
         week_name = new_str;
     };
 }; 

struct LectureTitle {
  string specialization;
  string course;
  string week;
  LectureTitle(Specialization new_sp, Course new_cr, Week new_wk) {
      specialization = new_sp.specialization_name;
      course = new_cr.course_name;
      week = new_wk.week_name;
  };
};


int main()
{

LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
);

  return 0;
}