#include <iostream>
#include <string>
using namespace std;

#include "playlist.h"

Playlist::Playlist(const string & aUID, const string & aPName){
	cout << "Playlist(string&, string&) " << this << endl;
	pName = aPName;
  UID = aUID;
}

// Copy Constructor
Playlist::Playlist(const Playlist & aPlaylist){
	cout << "Playlist(string&, string&) " << this << endl;
	pName = aPlaylist.pName;
  UID = aPlaylist.UID;
}

//Assignment Operator
Playlist &Playlist::operator=(const Playlist & aPlaylist){

	cout << "Playlist(string&, string&) " << this << endl;
	if(&aPlaylist != this){
		pName = aPlaylist.pName;
	  UID = aPlaylist.UID;
	}
	return *this;
}

Playlist::~Playlist(){
	cout << "~Playlist(void) "  << this << endl;
}
string Playlist::getID(){return UID;}

string Playlist::toString()const {
	return UID + " " + pName;
}

ostream & operator<<(ostream & out, const Playlist & aPlaylist){
	out << aPlaylist.toString() << endl;
	return out;
}
