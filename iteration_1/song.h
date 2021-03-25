/*Emmanuel Dairo 101010678
  Korede Adegboye 101001124
  Date: Sept.31/17
*/


#ifndef _SONG_H
#define _SONG_H

#include <ostream>
#include <string>

class Song {
	/*
	Song represents a musical composition (not an audio recording)
	*/
	public:
	Song(const string & aTitle, const string & aComposer, const int anId = -1);
	Song(const Song & aSong);
	Song & operator=(const Song & aSong);
	~Song(void);
    int getID();
    string toString() const;

	private:
	string title;
	string composer;
	int SID;
};

ostream & operator<<(ostream & out, const Song & aSong);

#endif
