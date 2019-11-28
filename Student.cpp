#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(){
    id = 0;
    name = "none";
    level = "none";
    major = "none";
    gpa = 0.0;
    advisor = 0;
}

Student::~Student(){

}

Student::Student(int studentID, string studentName, string studentGradeLevel, string studentMajor, double studentGPA, int studentAdvisor){
  id = studentID;
  name = studentName;
  level = studentGradeLevel;
  major = studentMajor;
  gpa = studentGPA;
  advisor = studentAdvisor;
}

int Student::getID(){
    return id;
}

int Student::getAdvisor(){
  return advisor;
}

string Student::getName(){
    return name;
}

double Student::getGPA(){
  return gpa;
}

void Student::printStudentInfo(){
  cout << "Student ID: " << id << endl;
  cout << "Name: " << name << endl;
  cout << "Major: " << major << endl;
  cout << "GPA: " << gpa << endl;
  cout << "Advisor ID: " << advisor << endl;
}
