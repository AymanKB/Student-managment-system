#ifndef ADMIN_HPP
#define ADMIN_HPP
#include "User.hpp"
#include "Student.hpp"
#include "Academician.hpp"
using namespace std;

class Admin: public User
{
	private:
		int faculty;

	public:
		Admin(string name, string id, string password, int faculty)
		{
			this -> name = name;
            this -> id = id;
            this -> password = password;
			this -> faculty = faculty;
		}
		void viewStudent();
        void viewLecturer();
        void viewCourse(Admin a);
        void addStudent();
        void deleteStudent();
        void addLecturer();
        void deleteLecturer();
        int getFaculty(){return faculty;}
};

#endif

