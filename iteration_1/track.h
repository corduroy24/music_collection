/*Emmanuel Dairo 101010678
  Korede Adegboye 101001124
  Date: Sept.31/17
*/


#ifndef _TRACK_H
#define _TRACK_H

#include <ostream>
#include <string>

class Track {
	/*
	Track represents a musical composition (not an audio recording)
	*/
	public:
	Track(const int atrkNo, const int aSID, const int aAId = -1);
	Track(const Track & aTrack);
	Track & operator=(const Track & aTrack);

	~Track(void);
    int getSID();
    int getAId();
    string toString() const;

	private:
	int trkNo;
	int SID;
	int AId;
};

ostream & operator<<(ostream & out, const Track & aTrack);

#endif
