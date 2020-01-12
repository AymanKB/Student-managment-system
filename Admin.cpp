#include "Admin.hpp"
#include "User.hpp"
#include <iostream>
using namespace std;


void Admin::viewStudent()
{
    vector<Student> students;
    ifstream fin;
    fin.open("files/Users.txt");
    vector<string> loginID;
    vector<string> loginPass;
    vector<int> loginType;

    int totalUsers;
    fin >> totalUsers;
    fin.ignore();

    for(int i = 0 ; i < totalUsers ; i++)
    {
        int logtype;
        string id;
        string pass;
        fin >> logtype;
        fin.ignore();
        getline(fin, id);
        getline(fin, pass);

        loginType.push_back(logtype);
        loginID.push_back(id);
        loginPass.push_back(pass);
    }
    fin.close();
    int logindex = -1;
    for(int i = 0 ; i < totalUsers ; i++)
    {
        if (loginType[i] == 3)
        {
            Student tempStu(loginID[i]);
            if(tempStu.getFaculty() == faculty)
            {
                students.push_back(tempStu);
            }
        }
    }
    if(students.size() == 0 ) cout << endl <<endl<< " There are no Students in your faculty"<<endl << endl;
    else cout << endl <<endl<< " Here are all students in your faculty"<<endl;
    for (int i = 0 ; i < students.size();i++)
    {
      cout << " " << i+1 << " - " << students[i].getName() << " " << students[i].getId() << endl;
    }


}

void Admin::viewLecturer()
{
    vector<Academician> lecturers;
    ifstream fin;
    fin.open("files/Users.txt");
    vector<string> loginID;
    vector<string> loginPass;
    vector<int> loginType;

    int totalUsers;
    fin >> totalUsers;
    fin.ignore();

    for(int i = 0 ; i < totalUsers ; i++)
    {
        int logtype;
        string id;
        string pass;
        fin >> logtype;
        fin.ignore();
        getline(fin, id);
        getline(fin, pass);

        loginType.push_back(logtype);
        loginID.push_back(id);
        loginPass.push_back(pass);
    }
    fin.close();
    int logindex = -1;
    for(int i = 0 ; i < totalUsers ; i++)
    {
        if (loginType[i] == 2)
        {
            Academician tempLec(loginID[i]);
            if(tempLec.getFaculty() == faculty)
            {
                lecturers.push_back(tempLec);
            }
        }
    }
    if(lecturers.size() == 0 ) cout << endl <<endl<< " There are no Lecturers in your faculty"<<endl << endl;
    else cout << endl <<endl<< " Here are all Lecturers in your faculty"<<endl;
    for (int i = 0 ; i < lecturers.size();i++)
    {
      cout << " " << i+1 << " - " << lecturers[i].getName() << " " << lecturers[i].getId() << endl;
    }
}

void Admin::viewCourse(Admin a)
{
    ifstream fin;
    fin.open("files/Courses.txt");
    vector<int> viewType;
    vector<int> viewFaculty;
    vector<string> viewCode;

    int totalCourse;
    fin >> totalCourse;
    fin.ignore();

    for(int i = 0 ; i < totalCourse ; i++)
    {
        int vwtype;
        int vwfaculty;
        string vwcode;
        fin >> vwtype;
        fin.ignore();
        fin >> vwfaculty;
        fin.ignore();
        getline(fin, vwcode);

        viewType.push_back(vwtype);
        viewFaculty.push_back(vwfaculty);
        viewCode.push_back(vwcode);
    }
    fin.close();
    int logindex = -1;
    for(int i = 0 ; i < totalCourse-1 ; i++)
    {
        if (viewFaculty[i] == a.getFaculty() )
        {
            cout << viewCode[i] << endl;
        }
    }

}

void Admin::addStudent()
{
    string sname;
    string sid;
    string spassword;

    cout << "Enter student name: " <<endl;
    cin >> sname;
    cout << "Enter student id: " <<endl;
    cin >> sid;
    cout << "Enter student password: " <<endl;
    cin >> spassword;

    Student toAdd(sname, sid, spassword, 0, faculty, 0);
    toAdd.writeToFile();

    ifstream fin;
    fin.open("files/Users.txt");
    vector<string> loginID;
    vector<string> loginPass;
    vector<int> loginType;

    int totalUsers;
    fin >> totalUsers;
    fin.ignore();

    for(int i = 0 ; i < totalUsers ; i++)
    {
        int logtype;
        string id;
        string pass;
        fin >> logtype;
        fin.ignore();
        getline(fin, id);
        getline(fin, pass);

        loginType.push_back(logtype);
        loginID.push_back(id);
        loginPass.push_back(pass);
    }
    fin.close();

    loginType.push_back(3);
    loginID.push_back(sid);
    loginPass.push_back(spassword);

    ofstream fout;
    fout.open("files/Users.txt");
    fout << loginID.size() << endl;
    for(int i = 0 ; i < loginID.size();i++)
    {
        fout<< loginType[i] <<endl;
        fout<< loginID[i] <<endl;
        fout<< loginPass[i] <<endl;
    }
    fout.close();


}

void Admin::deleteStudent()
{
    vector<Student> students;
    ifstream fin;
    fin.open("files/users.txt");
    vector<string> loginID;
    vector<string> loginPass;
    vector<int> loginType;

    int totalUsers;
    fin >> totalUsers;
    fin.ignore();

    for(int i = 0 ; i < totalUsers ; i++)
    {
        int logtype;
        string id;
        string pass;
        fin >> logtype;
        fin.ignore();
        getline(fin, id);
        getline(fin, pass);

        loginType.push_back(logtype);
        loginID.push_back(id);
        loginPass.push_back(pass);
    }
    fin.close();
    int logindex = -1;
    for(int i = 0 ; i < totalUsers ; i++)
    {
        if (loginType[i] == 3)
        {
            Student tempStu(loginID[i]);
            if(tempStu.getFaculty() == faculty)
            {
                students.push_back(tempStu);
            }
        }
    }
    if(students.size() == 0 ) cout << endl <<endl<< " There are no Students in your faculty"<<endl << endl;
    else cout << endl <<endl<< " Which students would you like to Delete? (input 0 to cancel)"<<endl;
    for (int i = 0 ; i < students.size();i++)
    {
      cout << " " << i+1 << " - " << students[i].getName() << " " << students[i].getId() << endl;
    }
     int userchoice;
	  cout << " Input: ";
	  cin >> userchoice;
	  while(userchoice < 0 || userchoice >students.size())
      {
          cout << " Error: Index out of bounds."<<endl;
          cout << " Input: ";
          cin >> userchoice;
      }
      if(userchoice == 0)  cout << endl <<endl<< " Deletion Canceled"<<endl << endl;
      else
      {
          for(int i = 0 ; i < loginID.size();i++)
        {
            if(students[userchoice - 1].getId() == loginID[i]) logindex = i;
        }
        loginID.erase(loginID.begin()+ logindex);
        loginPass.erase(loginPass.begin() + logindex);
        loginType.erase(loginType.begin()+ logindex);
      }

      ofstream fout;
      fout.open("files/Users.txt");
      fout << loginID.size() << endl;
      for(int i = 0 ; i < loginID.size();i++)
      {
          fout<< loginType[i] <<endl;
          fout<< loginID[i] <<endl;
          fout<< loginPass[i] <<endl;
      }
      fout.close();


}

void Admin::addLecturer()
{
    string lname;
    string lid;
    string lpassword;

    cout << "Enter lecturer name: " <<endl;
    cin >> lname;
    cout << "Enter lecturer id: " <<endl;
    cin >> lid;
    cout << "Enter lecturer password: " <<endl;
    cin >> lpassword;

    Academician toAdd(lname, lid, lpassword, faculty);
    toAdd.writeToFile();

    ifstream fin;
    fin.open("files/Users.txt");
    vector<string> loginID;
    vector<string> loginPass;
    vector<int> loginType;

    int totalUsers;
    fin >> totalUsers;
    fin.ignore();

    for(int i = 0 ; i < totalUsers ; i++)
    {
        int logtype;
        string id;
        string pass;
        fin >> logtype;
        fin.ignore();
        getline(fin, id);
        getline(fin, pass);

        loginType.push_back(logtype);
        loginID.push_back(id);
        loginPass.push_back(pass);
    }
    fin.close();

    loginType.push_back(2);
    loginID.push_back(lid);
    loginPass.push_back(lpassword);

    ofstream fout;
    fout.open("files/Users.txt");
    fout << loginID.size() << endl;
    for(int i = 0 ; i < loginID.size();i++)
    {
        fout<< loginType[i] <<endl;
        fout<< loginID[i] <<endl;
        fout<< loginPass[i] <<endl;
    }
    fout.close();
}

void Admin::deleteLecturer()
{
    vector<Academician> lecturers;
    ifstream fin;
    fin.open("files/Users.txt");
    vector<string> loginID;
    vector<string> loginPass;
    vector<int> loginType;

    int totalUsers;
    fin >> totalUsers;
    fin.ignore();

    for(int i = 0 ; i < totalUsers ; i++)
    {
        int logtype;
        string id;
        string pass;
        fin >> logtype;
        fin.ignore();
        getline(fin, id);
        getline(fin, pass);

        loginType.push_back(logtype);
        loginID.push_back(id);
        loginPass.push_back(pass);
    }
    fin.close();
    int logindex = -1;
    for(int i = 0 ; i < totalUsers ; i++)
    {
        if (loginType[i] == 2)
        {
            Academician tempLec(loginID[i]);
            if(tempLec.getFaculty() == faculty)
            {
                lecturers.push_back(tempLec);
            }
        }
    }
    if(lecturers.size() == 0 ) cout << endl <<endl<< " There are no Lecturers in your faculty"<<endl << endl;
    else cout << endl <<endl<< "  Which students would you like to Delete? (input 0 to cancel)"<<endl;
    for (int i = 0 ; i < lecturers.size();i++)
    {
      cout << " " << i+1 << " - " << lecturers[i].getName() << " " << lecturers[i].getId() << endl;
    }

    int userchoice;
	  cout << " Input: ";
	  cin >> userchoice;
	  while(userchoice < 0 || userchoice >lecturers.size())
      {
          cout << " Error: Index out of bounds."<<endl;
          cout << " Input: ";
          cin >> userchoice;
      }
      if(userchoice == 0)  cout << endl <<endl<< " Deletion Canceled"<<endl << endl;
      else
      {
          for(int i = 0 ; i < loginID.size();i++)
        {
            if(lecturers[userchoice - 1].getId() == loginID[i]) logindex = i;
        }
        loginID.erase(loginID.begin()+ logindex);
        loginPass.erase(loginPass.begin() + logindex);
        loginType.erase(loginType.begin()+ logindex);
      }

      ofstream fout;
      fout.open("files/Users.txt");
      fout << loginID.size() << endl;
      for(int i = 0 ; i < loginID.size();i++)
      {
          fout<< loginType[i] <<endl;
          fout<< loginID[i] <<endl;
          fout<< loginPass[i] <<endl;
      }
      fout.close();

}
