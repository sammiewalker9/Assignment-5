#include <iostream>

using namespace std;

class Student{
public:
  int id;
  string name;
  string level;
  string major;
  double gpa;
  int advisor;

  Student();
  ~Student();
  Student(int id, string name, string level, string major, double gpa, int advisor);

  int getAdvisor();

  int getID();
  double getGPA();
  string getName();

  void printStudentInfo();

};
