/*
This file contains all the functions we use, which we call in the main
*/

#include <iostream>
#include <fstream>
#include <string>
#include "FileHandler.h"
#include "Student.h"
#include "Faculty.h"
#include "GenTree.h"
#include "GenStack.h"


using namespace std;

TreeNode<Faculty> *ftree;
TreeNode<Student> *stree;
BST<Student> masterStudent;
BST<Faculty> masterFaculty;
GenStack <int> personStack(5);

std::ostream &operator<<(std::ostream &os, const Student& obj)
{
  os << "ID: " << obj.id << endl << "Name: " << obj.name << endl << "Level: " << obj.level << endl << "Major: " << obj.major << endl << "GPA: " << obj.gpa << endl << "Advisor's ID: " << obj.advisor << endl;
  return os;
}

std::ostream &operator<<(std::ostream &os, const Faculty& obj)
{
  os << "ID: " << obj.id << endl << "Name: " << obj.name << endl << "Level: " << obj.type << endl << "Department: " << obj.major << endl << "Advisee: " << obj.advisee << endl;
  return os;
}

std::istream &operator>>(std::istream &is, const Student& obj)
{
  is >> obj;
  return is;
}


FileHandler::FileHandler(){

};

FileHandler::~FileHandler(){

};

void FileHandler::readFile(){
  string line;
  int studentID;
  string studentName;
  string studentGradeLevel;
  string studentMajor;
  double studentGPA;
  int studentAdvisor;

  int facultyID;
  string facultyName;
  string facultyType;
  string facultyMajor;
  int facultyAdvisee;

  // open student table file so we can read in information
  string studentTable = "studentTable.txt";
  ifstream inFile(studentTable);
  if(inFile.fail()){
      cout << "Student file is not formatted correctly" << endl;
  }
  else{

      int i = 0;
      while(getline(inFile, line)){
          // every 7th line, change type of line we are reading in
          if(i%7 == 1){
             studentID = atoi(line.substr(0,4).c_str()); // read in line from 0th index to 4
          }
          else if(i%7 == 2){
              studentName = line.substr(0,5);

          }
          else if(i%7 == 3){
              studentGradeLevel = line.substr(0,8);

          }
          else if(i%7 == 4){
              studentMajor = line.substr(0,7);

          }
          else if(i%7 == 5){
              studentGPA = atof(line.substr(0,4).c_str());

          }
          else if(i%7 == 6){
              studentAdvisor = atoi(line.substr(0,4).c_str());

              // now that we have read in all the information from the file, create an object of a student and assign it's retrieved information
              createStudent(studentID, studentName, studentGradeLevel, studentMajor, studentGPA, studentAdvisor);
          }

          ++i;
      }
   }

   string facultyTable = "facultyTable.txt";
   ifstream inFile1(facultyTable);
   if(inFile1.fail()){
       cout << "File was not formatted properly" << endl;

   }
   else{
       int i = 0;
       while(getline(inFile1, line)){
           if(i%6 == 1){
              facultyID = atoi(line.substr(0,4).c_str());
           }
           else if(i%6 == 2){
               facultyName = line.substr(0,6);
           }
           else if(i%6 == 3){
               facultyType = line.substr(0,10);

           }
           else if(i%6 == 4){
               facultyMajor = line.substr(0,15);

           }
           else if(i%6 == 5){
               facultyAdvisee = atoi(line.substr(0,4).c_str());
               createFaculty(facultyID, facultyName, facultyType, facultyMajor, facultyAdvisee);
           }
           ++i;

       }
   }
}


void FileHandler::createStudent(int id, string name, string level, string major, double gpa, int advisor)
{
  Student s(id, name, level, major, gpa, advisor);
  masterStudent.insert(s.getID(), s);
}

void FileHandler::createFaculty(int id, string name, string type, string major, int advisee)
{
  Faculty f(id, name, type, major, advisee);
  masterFaculty.insert(f.getID(), f);
}

// the goal of this function is to print all students and their information
// option 1 in menu in main
void FileHandler::printStudents(){
    masterStudent.printTree();
}

// the goal of this function is to print all faculty members and their information
// option 2 in menu in main
void FileHandler::printFaculty(){
    masterFaculty.printTree();
}

// the goal of this function is to print a specific student, given their ID number
// option 3 in menu in main
void FileHandler::printStudent(){
    string inputID;
    int idFind;

    while(true){
      cout << "Enter a student ID: " << endl;
      cin >> inputID;

      idFind = atoi(inputID.c_str()); // convert string to integer so we can recognize ID

      if(masterStudent.search(idFind)){ // if ID exists, print the information for the student
        masterStudent.printSingle(idFind);
        break;
      }
      else{
        cout << "This student doesn't exist. Please enter a valid ID. " << endl;
      }
    }
}

// the goal of this function is to print a specific faculty member, given their ID number
// option 4 in menu in main
void FileHandler::printFac(){
    string inputID;
    int idFind;

    while(true){
      cout << "Enter a faculty ID: " << endl;
      cin >> inputID;

      idFind = atoi(inputID.c_str());

      if(masterFaculty.search(idFind)){
        masterFaculty.printSingle(idFind);
        break;
      }
      else{
        cout << "This faculty member doesn't exist. Please enter a valid ID. " << endl;
      }
    }

}

// the goal of this function is to delete a specific student, given their ID number
// option 8 in menu in main
void FileHandler::deleteStudent(){
    cout << "Enter a student ID: " << endl;
    int idFind;
    cin >> idFind;
    masterStudent.deleteNode(idFind);
    personStack.push(8);
}

// the goal of this function is to delete a specific faculty member, given their ID number
// option 10 in menu in main
void FileHandler::deleteFaculty(){
    cout << "Enter a faculty ID: " << endl;
    int idFind;
    cin >> idFind;
    masterFaculty.deleteNode(idFind);
    personStack.push(10);
}

// the goal of this function is to add a new student, user enters in all their information
// option 7 in menu in main
void FileHandler::addStudent(){
    cout << "ID: ";
    int addID;
    cin >> addID;

    cout << "Name: ";
    string addName;
    cin >> addName;

    cout << "Grade: ";
    string addLevel;
    cin >> addLevel;

    cout << "Major: ";
    string addMajor;
    cin >> addMajor;

    cout << "GPA: ";
    double addGPA;
    cin >> addGPA;

    cout << "Advisor: ";
    int addAdvisor;
    cin >> addAdvisor;
    //if id doesn't exist in the tree
    createStudent(addID, addName, addLevel, addMajor, addGPA, addAdvisor);
    // else{cout << "Student is already in tree << endl;"}
    personStack.push(7);
}

// the goal of this function is to add a new faculty member, user enters in all their information
// option 9 in menu in main
void FileHandler::addFaculty(){
    cout << "ID: ";
    int addID;
    cin >> addID;

    cout << "Name: ";
    string addName;
    cin >> addName;

    cout << "Grade: ";
    string addType;
    cin >> addType;

    cout << "Major: ";
    string addMajor;
    cin >> addMajor;

    cout << "Advisee: ";
    int addAdvisee;
    cin >> addAdvisee;
    //if id doesn't exist in the tree
    createFaculty(addID, addName, addType, addMajor, addAdvisee);
    // else{cout << "Student is already in tree << endl;"}
    personStack.push(9);
}


// option 13 in menu in main
void FileHandler::rollBack(){
    if(personStack.isEmpty()){
        cout << "Cannot undo last command" << endl;
    }
    else{
        if(personStack.pop() == 8){
            addStudent();
        }
        if(personStack.pop() == 10){
            addFaculty();
        }
        if(personStack.pop() == 7){
            deleteStudent();
        }
        if(personStack.pop() == 9){
            deleteFaculty();
        }
    }
}

// when exiting the program, this function will rewrite student and faculty tables with new information
// option 14 in menu in main
void FileHandler::writeFile(){
      ofstream outFile;
      outFile.open("studentTable.txt", ios_base::app); // open ouput file
      outFile << endl << "New Student table: " << endl;
      if(outFile.is_open()){
          masterStudent.printTreeOutStud();
      }
      else{
          cout << "Error writing to file" << endl;
      }

      ofstream outFile1;
      outFile1.open("facultyTable.txt", ios_base::app);
      outFile1 << endl << "New Faculty table: " << endl;
      if(outFile1.is_open()){
          masterFaculty.printTreeOutFac();
      }
      else{
          cout << "Error writing to file" << endl;
      }
}

// the goal of this function is to print the name and info of a students faculty advisor, given the students ID
// option 5 in menu in main
void FileHandler::printAdvisorGivenStudID(){
  string input;
  int studentID;

  while(true){
    cout << "Enter a studnet ID to print their Advisor: " << endl;
    cin >> input;

    studentID = atoi(input.c_str());

    if(masterStudent.search(studentID)){
      Student *stud = masterStudent.find(studentID);

      masterFaculty.find(stud->getAdvisor())->printFacultyInfo();
      break;
    }
    else{
      cout << "Studnet doesn't exist. Enter a valid ID. " << endl;
    }
  }
}

// the goal of this function is to print all the names of a faculty members advisee's, given their ID
// option 6 in menu in main
void FileHandler::printAdviseeGivenFac(){
  string input;
  int facultyID;

  while(true){
    cout << "Enter a faculty ID to get Advisee info: " << endl;
    cin >> input;

    facultyID = atoi(input.c_str());
    if(masterFaculty.search(facultyID)){
      Faculty *fac = masterFaculty.find(facultyID);
      for(int i = 0; i < fac->getArrayMaxSize(); i++){
        if(fac->adviseeArray[i] != -1){
          masterStudent.find(fac->adviseeArray[i])->printStudentInfo();
          break;

        }
        else{
          cout << "Faculty ID doesn't exist. Please enter a valid ID. " << endl;
        }
      }
    }

  }
}

// the goal of this function is to remove an advisee given student and faculty ID's
// option 12 in menu in main
void FileHandler::removeAdvisee(){
  string input;
  int studentID;
  int facultyID;

  while(true){
    cout << "Enter a faculty ID to change an advisee: " << endl;
    cin >> input;
    facultyID = atoi(input.c_str()); //convert string to int

    if(masterFaculty.search(facultyID)){ // if ID exists, find it and print advisee
      masterFaculty.find(facultyID)->printAdvisee();

      while(true){
        cout << "Enter a student ID: " << endl;
        cin >> input;

        studentID = atoi(input.c_str());

        if(masterStudent.search(studentID)){
          break;
        }
        else{
          cout << "Student doesn't exist. Please enter a valid ID. " << endl;
        }
      }
    }
    else{
      cout << "Faculty member doesn't exist. Please enter a valid ID. " << endl;
    }
  }
}
