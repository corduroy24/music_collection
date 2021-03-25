/*Emmanuel Dairo 101010678
  Korede Adegboye 101001124
  Date: Sept.31/17
*/

#ifndef _USERS_H
#define _USERS_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
//#include "UI.h"
#include "user.h"

class Users {
	/*
	Users represents a collection of compositions, specifically User objects.
	A Users container OWNS the Users within it.
	If the container is destroyed it deletes the User objects it contains
	If a User is removed from the container the User object is deleted from heap space.
	*/
	public:
	Users();
	~Users(void);
	User * findByID(string anID);
	void add(User & aUser);
	void remove(User & aUser);
	//void showOn(UI & aView) const;
	void printOn(ostream & out) const;

	private:
	vector<User*> collection;
	vector<User*>::iterator findPosition(User & aUser);
};

ostream & operator<<(ostream & out, const Users & users);
#endif
