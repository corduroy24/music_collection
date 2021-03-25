/*Emmanuel Dairo 101010678
  Korede Adegboye 101001124
  Date: Sept.31/17
*/

#include <iostream>
#include <string>
using namespace std;

#include "song.h"

Song::Song(const string & aTitle, const string & aComposer, const int anID){
	cout << "Song(string&, string&, int) " << this << endl;
	title = aTitle;
	composer = aComposer;
	SID = anID;
}

// Copy Constructor
Song::Song(const Song & aSong){
	cout << "Song(string&, string&, int) " << this << endl;
	title = aSong.title;
	composer = aSong.composer;
	SID = aSong.SID;
}

//Assignment Operator
Song &Song::operator=(const Song & aSong){

	cout << "Song(string&, string&, int) " << this << endl;
	if(&aSong != this){
		title = aSong.title;
		composer = aSong.composer;
		SID = aSong.SID;
	}
	return *this;
}


Song::~Song(){
	cout << "~Song(void) "  << this << endl;
}
int Song::getID(){return SID;}

string Song::toString()const {
	return to_string(SID) + " " + title + " " + composer;
}

ostream & operator<<(ostream & out, const Song & aSong){
	out << aSong.toString() << endl;
	return out;
}
