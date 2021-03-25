#ifndef _TRACKS_H
#define _TRACKS_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
//#include "UI.h"
#include "track.h"

class Tracks {
	/*
	Songs represents a collection of compositions, specifically Song objects.
	A Songs container OWNS the songs within it.
	If the container is destroyed it deletes the Song objects it contains
	If a Song is removed from the container the Song object is deleted from heap space.
	*/
	public:
	Tracks();
	~Tracks(void);
	Track * findBySID(int anID);
	Track * findByAId(int anID);
	void add(Track & aTrack);
	void remove(Track & aTrack);
	//void showOn(UI & aView) const;
	void printOn(ostream & out) const;

	private:
	vector<Track*> collection;
	vector<Track*>::iterator findPosition(Track & aTrack);
};

ostream & operator<<(ostream & out, const Tracks & Tracks);
#endif
