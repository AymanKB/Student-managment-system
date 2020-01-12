#include "Academician.hpp"
#include "User.hpp"
#include <iostream>

using namespace std;

void Academician::addCourse()
{
    string newname;
    string newcode;
    int newtype;
    int newcreditHours;
    int newfaculty;
    string newid;
    int newstatus;

    cout << "Enter subject name: " <<endl;
    cin >> newname;
    cout << "\nEnter subject code: " <<endl;
    cin >> newcode;
    cout << "\nEnter course type: \n" <<endl;
    cout << "1. Diploma" <<endl;
    cout << "2. Undergraduate" <<endl;
    cout << "3. Postgraduate" <<endl;
    cin >> newtype;
    cout << "\nEnter credit hour: " <<endl;
    cin >> newcreditHours;
    cout << "\nEnter course status: \n" <<endl;
    cout << "1. Course is still open" <<endl;
    cout << "2. Course is closed" << endl;
    cin >> newstatus;

    Course toAdd(newname, newcode, newtype, newcreditHours, faculty, id, newstatus);
    toAdd.writeToFile();
    lecturerC.push_back(toAdd);
    writeToFile();

    ifstream fin;
    fin.open("files/Courses.txt");
    vector<int> courseType;
    vector<int> cFaculty;
    vector<string> cCode;

    int totalCourse;
    fin >> totalCourse;
    fin.ignore();

    for(int i = 0 ; i < totalCourse ; i++)
    {
        int cotype;
        int cFac;
        string coCode;
        fin >> cotype;
        fin.ignore();
        fin >> cFac;
        fin.ignore();
        getline(fin, coCode);

        courseType.push_back(cotype);
        cFaculty.push_back(cFac);
        cCode.push_back(coCode);
    }
    fin.close();

    courseType.push_back(newtype);
    cFaculty.push_back(faculty);
    cCode.push_back(newcode);

    ofstream fout;
    fout.open("files/Courses.txt");
    fout << cCode.size() << endl;
    for(int i = 0 ; i < cCode.size();i++)
    {
        fout<< courseType[i] <<endl;
        fout<< cFaculty[i] <<endl;
        fout<< cCode[i] <<endl;
    }
    fout.close();

}

void Academician::deleteCourse()
{
   if (lecturerC.size() != 0 ) cout << endl <<endl<< " Which course would you like to delete? (input 0 to cancel)"<<endl;
   else
   {
       cout << endl <<endl<< " You don't have any course yet."<<endl;
       return;
   }
   for (int i = 0 ; i < lecturerC.size() ; i ++)
   {
       cout << " " << i + 1 << " - "<< lecturerC[i].getCode() << " - " << lecturerC[i].getName() << endl;
   }
   int userchoice;
      cout << " Input: ";
      cin >> userchoice;
      while(userchoice < 0 || userchoice >lecturerC.size())
      {
          cout << " Error: Index out of bounds."<<endl;
          cout << " Input: ";
          cin >> userchoice;
      }
      string courseToFind;
      if(userchoice == 0)  cout << endl <<endl<< " Deletion Canceled"<<endl << endl;
      else
      {

         courseToFind = lecturerC[userchoice-1].getCode();
          lecturerC.erase(lecturerC.begin()+(userchoice-1));

      }


   ifstream fin;
    fin.open("files/Courses.txt");
    vector<int> courseType;
    vector<int> cFaculty;
    vector<string> cCode;
    int logindex;

    int totalCourse;
    fin >> totalCourse;
    fin.ignore();

    for(int i = 0 ; i < totalCourse ; i++)
    {
        int cotype;
        int cFac;
        string coCode;
        fin >> cotype;
        fin.ignore();
        fin >> cFac;
        fin.ignore();
        getline(fin, coCode);

        courseType.push_back(cotype);
        cFaculty.push_back(cFac);
        cCode.push_back(coCode);
        if(coCode == courseToFind) logindex = i;
    }
    fin.close();


    courseType.erase(courseType.begin()+ logindex);
        cFaculty.erase(cFaculty.begin() + logindex);
        cCode.erase(cCode.begin()+ logindex);

   ofstream fout;
      fout.open("files/Courses.txt");
      fout << courseType.size() << endl;
      for(int i = 0 ; i < courseType.size();i++)
      {
          fout<< courseType[i] <<endl;
          fout<< cFaculty[i] <<endl;
          fout<< cCode[i] <<endl;
      }
      fout.close();
      writeToFile();
}

void Academician::viewCourses()
{
   if (lecturerC.size() != 0 ) cout << endl <<endl<< " Here are the details of your courses."<<endl;
   else cout << endl <<endl<< " You don't have any course yet."<<endl;
   for (int i = 0 ; i < lecturerC.size() ; i++)
   {
       cout << " " << lecturerC[i].getCode() << " - " << lecturerC[i].getName() << endl;
       cout << " Credit Hour: " << lecturerC[i].getHours() << endl << endl;
       cout << " Status: " ;
       if (lecturerC[i].getStatus()==0) cout << "Closed" << endl << endl;
       else cout << "Open" << endl << endl;
   }
}
void Academician::viewStudent()
{

}

void Academician::writeToFile()
{
    string appendf = "files/";
    string appendb = ".txt";
    string filename = appendf + id + appendb;
    ofstream fout;
    fout.open(filename);
    fout << name << endl;
    fout << id << endl;
    fout << faculty << endl;
    fout << lecturerC.size() <<endl;
    for(int i = 0 ; i < lecturerC.size();i++)
    {
      fout<< lecturerC[i].getCode()<<endl;
    }
    fout.close();
}
