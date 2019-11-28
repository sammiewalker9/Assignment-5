/*
Sammie Walker
2315055
swalker@chapman.edu
CPSC 350 - 03
Assignment 5
*/

#include "GenTree.h"
#include "GenStack.h"
#include "FileHandler.h"
using namespace std;

int main(){
  FileHandler q;

  q.readFile();
  while(true){
      cout << "Main Menu - Enter an integer 1 -14: " << endl;

      // display menu options to user
      cout << "1. Print Students" << endl << "2. Print Faculty" << endl << "3. Display student info given ID" << endl << "4. Display faculty info given ID" << endl << "5. Given a students ID, print info for faculty advisor" << endl << "6. Given a faculty ID, print info for advisee" << endl << "7. Add a new student" << endl << "8. Delete a student given an ID" << endl << "9. Add a new faculty member" << endl << "10. Delete a faculty member given an ID" << endl << "11. Change a students advisor given the student ID and the new faculty ID" << endl << "12. Remove an advisee from a faculty member given the IDs \n13. Rollback \n14. Exit" << endl;
      int menuOptions;
      cin >> menuOptions;

      // based on what the user enters, execute the appropriate function
      if(menuOptions == 1){
          cout << "Students: " << endl;
          q.printStudents();
      }
      else if(menuOptions == 2){
          cout << "Faculty: " << endl;
          q.printFaculty();
      }
      else if(menuOptions == 3){
          cout << "Display student info given ID" << endl;
          q.printStudent();
      }
      else if(menuOptions == 4){
          cout << "Display faculty info given ID" << endl;
          q.printFac();
      }
      else if(menuOptions == 5){
          cout << "Given a students ID, print info for faculty advisor" << endl;
          q.printAdvisorGivenStudID();
      }
      else if(menuOptions == 6){
          cout << "Given a faculty ID, print info for advisee" << endl;
          q.printAdviseeGivenFac();
      }
      else if(menuOptions == 7){
          q.addStudent();
          cout << "Student added." << endl;
      }
      else if(menuOptions == 8){
          q.deleteStudent();
          cout << "Student deleted." << endl;
      }
      else if(menuOptions == 9){
          q.addFaculty();
          cout << "Faculty added." << endl;
      }
      else if(menuOptions == 10){
          q.deleteFaculty();
          cout << "Faculty deleted." << endl;
      }
      else if(menuOptions == 11){
          cout << "Change a student's advisor given the student id and the new faculty ID" << endl;
          cout << "Advisor changed." << endl;
      }
      else if(menuOptions == 12){
          cout << "Remove an advisee from a faculty member given the IDs" << endl;
          q.removeAdvisee();
          cout << "Advisee removed" << endl;
      }
      else if(menuOptions == 13){
          cout << "Rollback" << endl;
          q.rollBack();
      }
      else if(menuOptions == 14){
        cout << "Exit" << endl;
        ofstream outFile, outFile1;
        outFile.open("studentTable.txt", std::ofstream::out | std::ofstream::trunc);
        outFile1.open("facultyTable.txt", std::ofstream::out | std::ofstream::trunc);
        outFile.close();
        outFile1.close();
        q.writeFile();
        exit(EXIT_FAILURE);

        //call fac funciton
      }
      else{
          cout << "You didn't enter an integer 1 - 14" << endl;
      }
  }

}
