/*
This file contains all information needed for faculty memebers and their advisee's
*/

#include "Faculty.h"

using namespace std;

Faculty::Faculty(){
  id = 0;
  name = "none";
  type = "none";
  major = "none";
}

Faculty::~Faculty(){

};

Faculty::Faculty(int facultyID, string facultyName, string facultyType, string facultyMajor, int facultyAdvisee){
  id = facultyID;
  name = facultyName;
  type = facultyType;
  major = facultyMajor;
  advisee = facultyAdvisee;

  adviseeArray = new int[5]; // create an array of advisee's so that we can search through it in functions later
  numAdvisee = 0;
  maxSize = 5;

  for(int i = 0; i < 5; i++){
    adviseeArray[i] = -1;
  }

}

int Faculty::getID(){
    return id;
}

void Faculty::printFacultyInfo(){
  cout << "Faculty ID: " << id << endl;
  cout << "Name: " << name << endl;
  cout << "Profession: " << type << endl;
  cout << "Department: " << major << endl;
}

int Faculty::getAdvisee(){
  return advisee;
}

string Faculty::getProfessorType(){
  return type;
}

bool Faculty::removeAdvisee(int adviseeID){
  bool removed = false;
  for(int i = 0; i < maxSize; i++){
    if(adviseeArray[i] == adviseeID){
      adviseeArray[i] = -1; 
      --numAdvisee;
      removed = true;
    }
    return removed;
  }
}

int Faculty::getArrayMaxSize(){
  return maxSize;
}

void Faculty::printAdvisee(){
  if(numAdvisee==0){
    cout << "No advisses. " << endl;
  }
  else{
    for(int i = 0; i < maxSize; i++){
      if(adviseeArray[i] != 1){
        cout << adviseeArray[i];
        if(i < numAdvisee - 1){ // while there's still advisee's to print, add a comma inbetween each
          cout << ", ";
        }
      }
    }
  }
  cout << endl;
}
