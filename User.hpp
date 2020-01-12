#ifndef USER_HPP
#define USER_HPP
using namespace std;

class User
{
	protected:

	string name;
	string id;
	string password;

	public:
	User(){};
	User(string name, string id, string password )
	{
		this -> name = name;
		this -> id = id;
		this -> password = password;
	}

	void setName(string name)
	{
		this ->name = name;
	}
	string getName()
	{
		return name;
	}

	void setId(string id)
	{
		this ->id = id;
	}
	string getId(){
		return id;
	}

	void setPassword()
	{
		this ->password = password;
	}
	string getPassword()
	{
		return password;
	}


};

#endif


