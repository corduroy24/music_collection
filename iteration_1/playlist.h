#ifndef _PLAYLIST_H
#define _PLAYLIST_H

#include <ostream>
#include <string>

class Playlist {
	/*
	Song represents a musical composition (not an audio recording)
	*/
	public:
	Playlist(const string & aUID, const string & aPName);
	Playlist(const Playlist & aPlaylist);
	Playlist & operator=(const Playlist & aPlaylist);

	~Playlist(void);
    string getID();
    string toString() const;

	private:
	string pName;
	string UID;
};

ostream & operator<<(ostream & out, const Playlist & aPlaylist);

#endif
