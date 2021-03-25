#include <iostream>
#include <string>
using namespace std;

#include "user.h"

User::User(const string & aUID, const string & aName){
	cout << "User(string&, string&) " << this << endl;
	name = aName;
  UID = aUID;
}

// Copy Constructor
User::User(const User & aUser){
	cout << "User(string&, string&) " << this << endl;
	name = aUser.name;
  UID = aUser.UID;
}

//Assignment Operator
User &User::operator=(const User & aUser){

	cout << "User(string&, string&) " << this << endl;
	if(&aUser != this){
		name = aUser.name;
	  UID = aUser.UID;
	}
	return *this;
}

User::~User(){
	cout << "~User(void) "  << this << endl;
}
string User::getID(){return UID;}

string User::toString()const {
	return UID + " " + name;
}

ostream & operator<<(ostream & out, const User & aUser){
	out << aUser.toString() << endl;
	return out;
}
