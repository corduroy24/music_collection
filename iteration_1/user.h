#ifndef _USER_H
#define _USER_H

#include <ostream>
#include <string>

class User {
	/*
	Song represents a musical composition (not an audio recording)
	*/
	public:
	User(const string & aUID, const string & aName);
	User(const User & aUser);
	User & operator=(const User & aUser);

	~User(void);
    string getID();
    string toString() const;

	private:
	string name;
	string UID;
};

ostream & operator<<(ostream & out, const User & aUser);

#endif
