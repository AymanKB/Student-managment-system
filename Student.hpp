#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "User.hpp"
#include "Course.hpp"
using namespace std;

class Student: public User
{
	private:
		int type;
		int faculty;
		int totalCreditHours;
		vector <Course> studentC;

	public:
		Student(string name, string id, string password, int type, int faculty, int totalCreditHours)
		{
			this -> name = name;
            this -> id = id;
            this -> password = password;
            this -> faculty = faculty;
			this ->type = type;
			this -> totalCreditHours = totalCreditHours;
			vector <Course> studentC;
		}
		Student(string fname)
		{
		    ifstream fin;
		    string appendf = "files/";
            string appendb = ".txt";
            fname = appendf + fname + appendb;
            fin.open(fname);
            getline(fin,name);
            getline(fin,id);
            fin >> type;
            fin.ignore();
            fin >> faculty;
            fin.ignore();
            int courseNo;
            fin >> courseNo;
            fin.ignore();
            int hours = 0;
            string courseCode;
            for (int i = 0 ; i < courseNo ; i ++)
            {
                getline(fin,courseCode);
                Course tempCourse(courseCode);
                studentC.push_back(tempCourse);
                hours = hours + tempCourse.getHours();
            }


		}
		void setType(int type)
		{
			this ->type = type;
		}

		int getType()
		{
			return type;
		}

		void setHours(int totalCreditHours)
		{
			this ->totalCreditHours = totalCreditHours;
		}

		int getHours()
		{
			return totalCreditHours;
		}

		int getFaculty()
		{
			return faculty;
		}

		vector<Course> getStudentC()
		{
			return studentC;
		}
		void addCourse(Course toAdd)
		{
		    studentC.push_back(toAdd);
		    return;
		}
		void enroll();
        void registerCourse();
        void course();
        void writeToFile();

};

#endif

