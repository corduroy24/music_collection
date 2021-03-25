/*Emmanuel Dairo 101010678
  Korede Adegboye 101001124
  Date: Sept.31/17
*/

#include <iostream>
#include <string>
using namespace std;

#include "recording.h"

Recording::	Recording(const string & aTitle, const string & aArtist, const string & aProducer, const int aYear, const int anId){
	cout << "Recording(string&, string&, string&, int, int) " << this << endl;
	title = aTitle;
	producer = aProducer;
  artist= aArtist;
  year= aYear;
	AId = anId;
}

// Copy Constructor
Recording::Recording(const Recording & aRecording){
	cout << "Recording(string&, string&, string&, int, int) " << this << endl;
	title = aRecording.title;
	producer = aRecording.producer;
  artist= aRecording.artist;
  year= aRecording.year;
	AId = aRecording.AId;
}

//Assignment Operator
Recording &Recording::operator=(const Recording & aRecording){

	cout << "Recording(string&, string&, string&, int, int) " << this << endl;
	if(&aRecording != this){
		title = aRecording.title;
		producer = aRecording.producer;
	  artist= aRecording.artist;
	  year= aRecording.year;
		AId = aRecording.AId;
	}
	return *this;
}
Recording::~Recording(){
	cout << "~Recording(void) "  << this << endl;
}
int Recording::getID(){return AId;}

string Recording::toString()const {
	return to_string(AId) + " " + to_string(year)+ " " + title + " " + producer+" "+ artist;
}

ostream & operator<<(ostream & out, const Recording & aRecording){
	out << aRecording.toString() << endl;
	return out;
}
