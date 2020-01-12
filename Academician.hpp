#ifndef ACADEMICIAN_HPP
#define ACADEMICIAN_HPP
#include "Course.hpp"
#include "User.hpp"
using namespace std;

class Academician: public User
{
	private:
        int faculty;
        vector <Course> lecturerC;

	public:
        Academician(string name, string id, string password,int faculty)
        {
            this -> name = name;
            this -> id = id;
            this -> password = password;
            this -> faculty = faculty;
        }

        Academician(string fname)
		{
		    ifstream fin;
		    string appendf = "files/";
            string appendb = ".txt";
            fname = appendf + fname + appendb;
            fin.open(fname);
            getline(fin,name);
            getline(fin,id);
            fin >> faculty;
            fin.ignore();
            int courseNo;
            fin >> courseNo;
            fin.ignore();
            string courseCode;
            for (int i = 0 ; i < courseNo ; i ++)
            {
                getline(fin,courseCode);
                Course tempCourse(courseCode);
                lecturerC.push_back(tempCourse);
            }

		}

        vector<Course> getLecturerC()
        {
            return lecturerC;
        }

        void addCourse(Course toAdd)
        {
            lecturerC.push_back(toAdd);
        }

        int getFaculty()
        {
            return faculty;
        }

        void addCourse();
        void deleteCourse();
        void viewCourses();
        void viewStudent();
        void writeToFile();

};

#endif

