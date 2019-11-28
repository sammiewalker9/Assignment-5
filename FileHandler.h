#include <iostream>

using namespace std;

class FileHandler{
public:

  //BST<Student>masterStudent;
  //BST<Faculty>masterFaculty;

  FileHandler();
  ~FileHandler();

  void readFile();
  void writeFile(string fileName);

  void createFaculty(int id, string name, string type, string major, int advisee);
  void createStudent(int id, string name, string level, string major, double gpa, int advisor);
  void printStudents();
  void printFaculty();
  void printStudent();
  void printFac();
  void addStudent();
  void addFaculty();
  void deleteStudent();
  void deleteFaculty();
  void rollBack();
  void writeFile();
  void removeAdvisee();
  void printAdvisorGivenStudID();
  void printAdviseeGivenFac();
};
