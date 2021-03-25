/*Emmanuel Dairo 101010678
  Korede Adegboye 101001124
  Date: Sept.31/17
*/

#ifndef _PLAYLISTS_H
#define _PLAYLISTS_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
//#include "UI.h"
#include "playlist.h"

class Playlists {
	/*
	Playlists represents a collection of compositions, specifically Playlist objects.
	A Playlists container OWNS the Playlists within it.
	If the container is destroyed it deletes the Playlist objects it contains
	If a Playlist is removed from the container the Playlist object is deleted from heap space.
	*/
	public:
	Playlists();
	~Playlists(void);
	Playlist * findByID(string anID);
	void add(Playlist & aPlaylist);
	void remove(Playlist & aPlaylist);
	//void showOn(UI & aView) const;
	void printOn(ostream & out) const;

	private:
	vector<Playlist*> collection;
	vector<Playlist*>::iterator findPosition(Playlist & aPlaylist);
};

ostream & operator<<(ostream & out, const Playlists & playlists);
#endif
