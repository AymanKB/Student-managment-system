#ifndef COURSE_HPP
#define COURSE_HPP
#include "User.hpp"
#include <fstream>
using namespace std;

class Course
{
	private:
		string name;
		string code;
		int type;
		int creditHours;
		int faculty;
		string incharge;
		int status;
		vector<string> sectionLecturer;
		vector<string> sectionTutorial;
		vector<string> lectStudents;
		vector<string> tutStudents;


	public:
		Course(string name, string code, int type, int creditHours , int faculty, string incharge , int status)
		{
			this ->name = name;
			this ->code = code;
			this ->type = type;
			this ->creditHours = creditHours;
			this ->faculty = faculty;
			this ->incharge = incharge;
			this ->status = status;
		}
		Course(string fname)
		{

		    ifstream fin;
		    string appendf = "files/";
            string appendb = ".txt";
            fname = appendf + fname + appendb;
            fin.open(fname);
            getline(fin,name);
            getline(fin,code);
            fin >> type;
            fin.ignore();
            fin >> creditHours;
            fin.ignore();
            fin >> faculty;
            fin.ignore();
            getline(fin,incharge);
            fin >> status;
            fin.ignore();
            fin.close();
		}
		void setName(string name)
		{
			this ->name = name; //pointer private name = name parameter
		}

		string getName()
		{
			return name;
		}

		void setCode(string code)
		{
			this ->code = code; //pointer private name = name parameter
		}

		string getCode()
		{
			return code;
		}
		void setType(int type)
		{
			this ->type = type; //pointer private name = name parameter
		}

		int getType()
		{
			return type;
		}
		void setHours(int creditHours)
		{
			this ->creditHours = creditHours;
		}

		int getHours()
		{
			return creditHours;
		}
		int getFaculty()
		{
			return faculty;
		}

		void setFacuty(int faculty)
		{
			this ->faculty = faculty;
		}



		void setIncharge(string incharge)
		{
			this ->incharge = incharge;
		}

		string getIncharge()
		{
			return incharge;
		}

		void getStatus(int status)
		{
			this ->status = status;
		}

		int getStatus()
		{
			return status;
		}

		void writeToFile()
		{
		    string appendf = "files/";
            string appendb = ".txt";
            string filename = appendf + code + appendb;
            ofstream fout;
            fout.open(filename);
            fout << name << endl;
            fout << code << endl;
            fout << type << endl;
            fout << creditHours << endl;
            fout << faculty << endl;
            fout << incharge << endl;
            fout << status <<endl;

            fout.close();
		}

};

#endif

