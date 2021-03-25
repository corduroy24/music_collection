#ifndef _RECORDINGS_H
#define _RECORDINGS_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
//#include "UI.h"
#include "recording.h"

class Recordings {
	/*
	Songs represents a collection of compositions, specifically Song objects.
	A Songs container OWNS the songs within it.
	If the container is destroyed it deletes the Song objects it contains
	If a Song is removed from the container the Song object is deleted from heap space.
	*/
	public:
	Recordings();
	~Recordings(void);
	Recording * findByID(int anID);
	void add(Recording & aRecording);
	void remove(Recording & aRecording);
	//void showOn(UI & aView) const;
	void printOn(ostream & out) const;

	private:
	vector<Recording*> collection;
	vector<Recording*>::iterator findPosition(Recording & aRecording);
};

ostream & operator<<(ostream & out, const Recordings & recordings);
#endif
