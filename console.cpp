#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <sstream>
#include <fstream>
#include "User.hpp"
#include "Admin.cpp"
#include "Academician.cpp"
#include "Student.cpp"
#include "Course.hpp"




using namespace std;


void adminPage(string filenm,string password)
{
    ifstream fin;
	string name;
    string id ;
	int faculty;
	fin.open(filenm);
	getline(fin,name);
	getline(fin,id);
    fin >> faculty;
    fin.ignore();
    Admin curAdmin(name,id,password,faculty);
	fin.close();



	system("cls");
	cout << " Welcome, " << curAdmin.getName() << endl << endl;
	cout << " ID : " << id << endl;

	cout << " Faculty : ";
	switch(faculty)
	{
        case 1: cout << "Faculty of Computer Informatics\n" << endl; break;
        case 2: cout << "Faculty of Engineering\n" << endl; break;
        case 3: cout << "Faculty of Management\n" << endl; break;
        default: cout << "Error. Faculty unknown.";
	}

	cout << " What would you like to do?" << endl;
	cout << " 1 - View Student" << endl;
	cout << " 2 - View Lecturer" << endl;
	cout << " 3 - View course" << endl;
	cout << " 4 - Add student" << endl;
	cout << " 5 - Delete student" << endl;
	cout << " 6 - Add lecturer" << endl;
	cout << " 7 - Delete lecturer" << endl;
	int userchoice;
	cout << " Input: ";
	cin >> userchoice;

	switch(userchoice)
	{
        case 1: curAdmin.viewStudent(); break;
		case 2: curAdmin.viewLecturer(); break;
		case 3: curAdmin.viewCourse(curAdmin); break;
		case 4: curAdmin.addStudent(); break;
		case 5: curAdmin.deleteStudent(); break;
		case 6: curAdmin.addLecturer(); break;
		case 7: curAdmin.deleteLecturer(); break;
        default: cout << "Wrong admin input";
	}
}
void lecturerPage(string filenm,string password)
{
    ifstream fin;
	string name;
    string id ;
    string courseCode;
    vector<Course> courses;
	int faculty;
	int courseNo;
	fin.open(filenm);
	getline(fin,name);
	getline(fin,id);
    fin >> faculty;
    fin.ignore();
    fin >> courseNo;
    fin.ignore();
    Academician curAcademician(name,id,password,faculty);
    for(int i = 0 ; i < courseNo ; i++)
    {

        getline(fin,courseCode);
        courses.push_back(courseCode);
    }
    fin.close();
    for(int i = 0 ; i < courses.size();i++)
    {

        Course toAdd(courses[i]);
        curAcademician.addCourse(toAdd);
    }



	system("cls");
	cout << " Welcome, " << curAcademician.getName() << endl << endl;
	cout << " ID : " << id << endl;

	cout << " Faculty : ";
	switch(faculty)
	{
        case 1: cout << "Faculty of Computer Informatics\n" << endl; break;
        case 2: cout << "Faculty of Engineering\n" << endl; break;
        case 3: cout << "Faculty of Management\n" << endl; break;
        default: cout << "Error. Faculty unknown.";
	}

	cout << " Courses: " << endl ;
	cout << " -------------------------------------------------------------------------------" <<endl;
	if(courseNo == 0)
    {
        cout<<" You do not have any course added" << endl;
    }
    else
    {
        for(int i = 0 ; i < curAcademician.getLecturerC().size() ; i ++)
        {
          cout << " " << i+1 << " - " << curAcademician.getLecturerC()[i].getCode() << " : " << curAcademician.getLecturerC()[i].getName() << endl;
        }
    }

    cout << " -------------------------------------------------------------------------------" <<endl << endl;


	cout << " What would you like to do?" << endl;
	cout << " 1 - Add course" << endl;
	cout << " 2 - Delete course" << endl;
	cout << " 3 - View course" << endl;
	cout << " 4 - View students" << endl;
	int userchoice;
	cout << " Input: ";
	cin >> userchoice;

	switch(userchoice)
	{
        case 1:   curAcademician.addCourse(); break;
        case 2:   curAcademician.deleteCourse(); break;
        case 3:   curAcademician.viewCourses(); break;
		case 4:   curAcademician.viewStudent(); break;
        default: cout << "Wrong input";
	}
}
void studentPage(string filenm,string password)
{


	ifstream fin;
	vector <string> courses;
	string name;
    string id ;
    int type;
	int faculty;
	int courseNo;
	int credit = 0;
	string courseCode;
	fin.open(filenm);
	getline(fin,name);
	getline(fin,id);
	fin >> type;
    fin.ignore();
    fin >> faculty;
    fin.ignore();
    fin >> courseNo;
    fin.ignore();
    Student curStudent(name,id,password,type,faculty,credit);
    for(int i = 0 ; i < courseNo ; i++)
    {

        getline(fin,courseCode);
        courses.push_back(courseCode);
    }
    fin.close();
    for(int i = 0 ; i < courses.size();i++)
    {

        Course toAdd(courses[i]);
        curStudent.addCourse(toAdd);
        credit = credit + toAdd.getHours();
        curStudent.setHours(credit);
    }





	system("cls");
	cout << " Welcome, " << curStudent.getName() << endl << endl;
	cout << " ID : " << id << endl;

	cout << " Faculty : ";
	switch(faculty)
	{
        case 1: cout << "Faculty of Computer Informatics\n" << endl; break;
        case 2: cout << "Faculty of Engineering\n" << endl; break;
        case 3: cout << "Faculty of Management\n" << endl; break;
        default: cout << "Error. Faculty unknown.";
	}

	cout << " Enrollment : ";
	switch(type)
	{
        case 0: cout << "Not Enrolled" << endl; break;
        case 1: cout << "Diploma" << endl; break;
        case 2: cout << "Undergraduate" << endl; break;
        case 3: cout << "Post-Graduate" << endl; break;
        default: cout << "Error. Enrollment unknown.";
	}

	cout << " Total Credit Hour: " << credit << endl;

	cout << " Courses: " << endl ;
	cout << " -------------------------------------------------------------------------------" <<endl;
	if(courseNo == 0)
    {
        cout<<" You are not registered in any course" << endl;
    }
    else
    {

        for(int i = 0 ; i < curStudent.getStudentC().size() ; i ++)
        {
          cout << " " << i+1 << " - " << curStudent.getStudentC()[i].getCode() << " : " << curStudent.getStudentC()[i].getName() << endl;
        }
    }

    cout << " -------------------------------------------------------------------------------" <<endl << endl;


	cout << " What would you like to do?" << endl;
	cout << " 1 - Enroll" << endl;
	cout << " 2 - Register course" << endl;
	cout << " 3 - View my courses" << endl;
	int userchoice;
	cout << " Input: ";
	cin >> userchoice;

	switch(userchoice)
	{
        case 1:   curStudent.enroll(); break;
        case 2:   curStudent.registerCourse(); break;
        case 3:   curStudent.course(); break;
        default: cout << "Wrong input";
	}

}

int main()
{
	string username = " ";
	string password = " ";
	bool loginSuccess = false;
    char login = 'Y';
    while (login == 'Y' || login == 'y')
    {
        system("cls");
        cout << " Welcome to Student Management System\n" << endl;
        cout << " Please enter username and password\n" << endl;

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


        do
        {
            cout << " Username: ";
            cin >> username;
            cout << " Password: ";
            cin >> password;



            for(int i = 0 ; i < loginID.size();i++)
            {
                if(username == loginID[i]) logindex = i;
            }

            if(logindex < 0)
            {
                cout << " Username does not exist"<<endl;
                continue;
            }
            else
            {
                if(loginPass[logindex] != password)
                {
                    cout << " Wrong Password"<<endl;
                    continue;
                }
                else loginSuccess = true;
            }


        }while (!loginSuccess);

        string frontAppend = "files/";
        string backAppend = ".txt";
        string filenm = frontAppend + loginID[logindex] + backAppend;
        char stop = 'N';
        while (stop == 'N' || stop == 'n')
        {
            switch(loginType[logindex])
            {
                case 1: adminPage(filenm,password); break;
                case 2: lecturerPage(filenm,password); break;
                case 3: studentPage(filenm,password); break;
                default: cout << "Error. User type is unknown.";
            }
            cout << endl <<" Are you done?";
            string temp;
            cin >> temp;
            stop = temp[0];
        }
        cout << endl <<" Would you like to login to other account?";
        string temp;
        cin >> temp;
        login = temp[0];
    }

}


