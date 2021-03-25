/*Emmanuel Dairo 101010678
  Korede Adegboye 101001124
  Date: Sept.31/17
*/

#include <iostream>
#include <string>
using namespace std;

#include "track.h"

Track::Track(const int atrkNo, const int aSID, const int aAId){
	cout << "Track(int, int, int) " << this << endl;
	trkNo = atrkNo;
	AId = aAId;
	SID = aSID;
}

// Copy Constructor
Track::Track(const Track & aTrack){
	cout << "Track(int, int, int) " << this << endl;
	trkNo = aTrack.trkNo;
	AId = aTrack.AId;
	SID = aTrack.SID;
}

//Assignment Operator
Track &Track::operator=(const Track & aTrack){
	cout << "Track(int, int, int) " << this << endl;
	if(&aTrack != this){
		trkNo = aTrack.trkNo;
		AId = aTrack.AId;
		SID = aTrack.SID;
	}
	return *this;
}

Track::~Track(){
	cout << "~Track(void) "  << this << endl;
}
int Track::getSID(){return SID;}
int Track::getAId(){return AId;}

string Track::toString()const {
	return to_string(AId) +" "+ to_string(SID) + " " + to_string(trkNo);
}

ostream & operator<<(ostream & out, const Track & aTrack){
	out << aTrack.toString() << endl;
	return out;
}
