#include <iostream>

using namespace std;

class Faculty{
public:
    int id;
    string name;
    string type;
    string major;
    int advisee;

    unsigned int numAdvisee;
    unsigned int maxSize;

    int *adviseeArray;

  Faculty();
  ~Faculty();
  Faculty(int id, string name, string type, string major, int advisee);

  void printFacultyInfo();

  string getProfessorType();
  int getAdvisee();
  int getID();
  bool removeAdvisee(int adviseeID);
  int getArrayMaxSize();
  void printAdvisee();

};
