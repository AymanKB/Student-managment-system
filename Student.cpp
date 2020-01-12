#include "Student.hpp"
#include "User.hpp"
#include <iostream>
using namespace std;


void Student::enroll()
{

  if(type != 0)
  {
      cout << endl <<endl<< " You have already enrolled."<<endl;
  }
  else
  {
      cout << endl << " Enrolling"<<endl<<endl;
      cout << " Please choose a program that you wish to enroll :"<<endl;
      cout << " 1 - Diploma" << endl;
      cout << " 2 - Undergraduate" << endl;
	  cout << " 3 - Post-Graduate" << endl;
	  int userchoice;
	  cout << " Input: ";
	  cin >> userchoice;
	  while(userchoice < 1 || userchoice >3)
      {
          cout << " Error: Index out of bounds."<<endl;
          cout << " Please choose a program that you wish to enroll :"<<endl;
          cout << " 1 - Diploma" << endl;
          cout << " 2 - Undergraduate" << endl;
          cout << " 3 - Post-Graduate" << endl;
          cout << " Input: ";
          cin >> userchoice;
      }
      type = userchoice;
       cout << endl << " You have enrolled"<<endl<<endl;

       writeToFile();

  }


}

void Student::registerCourse()
{
   vector<string> courseCodes;
   ifstream fin;
   fin.open("files/Courses.txt");

    int totalCourses;
    fin >> totalCourses;
    fin.ignore();

    for(int i = 0; i < totalCourses; i++)
    {
        int courseType;
        int courseFaculty;
        string courseCode;
        fin >> courseType;
        fin.ignore();
        fin >> courseFaculty;
        fin.ignore();
        getline(fin,courseCode);
        if(courseType==type && courseFaculty==faculty)
        {
            courseCodes.push_back(courseCode);
        }
    }
    fin.close();
    if(courseCodes.size() != 0)
   {
       cout << endl << " Choose a Course to Add" << endl<<endl;
   }
   else
   {
       cout << endl << " Sorry, there are no offered course for you right now" << endl;
       return;
   }

    for(int i = 0 ; i < courseCodes.size() ; i++)
    {
        string appendf = "files/";
        string appendb = ".txt";
        string filename = appendf + courseCodes[i] + appendb;
        string courseName;
        fin.open(filename);
        getline(fin,courseName);
        fin.close();
        cout << " " << i << " - " << courseName <<endl;
    }
    int userchoice;
    cout << " Input: ";
    cin >> userchoice;
    while(userchoice < 0 || userchoice > courseCodes.size())
    {
          cout << " Error: Index out of bounds."<<endl;
          cout << " Input: ";
          cin >> userchoice;
    }

    Course toAdd(courseCodes[userchoice]);

    if(toAdd.getStatus() == 0)
    {
        cout << "Course is closed by Instructor." << endl;
    }
    else
    {
        if((totalCreditHours+toAdd.getHours())>22)
        {
            cout << "You have too much Credit Hour" << endl;
        }
        else
        {
            studentC.push_back(toAdd);
            totalCreditHours = totalCreditHours + toAdd.getHours();
            cout << " Registration completed" << endl;
        }
    }
    writeToFile();
}

void Student::writeToFile()
{
      string appendf = "files/";
      string appendb = ".txt";
      string filename = appendf + id + appendb;
      ofstream fout;
      fout.open(filename);
      fout << name << endl;
      fout << id << endl;
      fout << type << endl;
      fout << faculty << endl;
      fout << studentC.size() <<endl;
      for(int i = 0 ; i < studentC.size();i++)
      {
          fout<< studentC[i].getCode()<<endl;
      }
      fout.close();
}

void Student::course()
{

   if (studentC.size() != 0 ) cout << endl <<endl<< " Here are the details of your courses."<<endl;
   else cout << endl <<endl<< " You don't have any course yet."<<endl;
   for (int i = 0 ; i < studentC.size() ; i++)
   {
       cout << " " << studentC[i].getCode() << " - " << studentC[i].getName() << endl;
       cout << " Lecturer ID: " << studentC[i].getIncharge() << endl;
       cout << " Credit Hour: " << studentC[i].getHours() << endl << endl;
   }
}
