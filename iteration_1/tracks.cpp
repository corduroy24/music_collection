/*Emmanuel Dairo 101010678
  Korede Adegboye 101001124
  Date: Sept.31/17
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "tracks.h"
#include "track.h"

Tracks::Tracks(){
}
Tracks::~Tracks(void){
	for(vector<Track*>::size_type i=0; i<collection.size(); i++)
		delete collection[i]; //delete Tracks in this container
}
vector<Track*>::iterator Tracks::findPosition(Track & aTrack){
	for (vector<Track*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if(*it == &aTrack) return it;
	return collection.end();
}
Track * Tracks::findByAId(int anID){
	for (vector<Track*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if((*it)->getAId() == anID) return *it;
	return NULL;
}
Track * Tracks::findBySID(int anID){
	for (vector<Track*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if((*it)->getSID() == anID) return *it;
	return NULL;
}
void Tracks::add(Track & aTrack){
	collection.push_back(&aTrack);
}
void Tracks::remove(Track & aTrack){
	vector<Track*>::iterator index = findPosition(aTrack);
	if(index != collection.end()) {
		Track * theTrack = *index;
		collection.erase(index);
		delete theTrack; //free the memory of theTrack
	}
}
/*
void Tracks::showOn(UI & view) const {
  view.printOutput("TRACKS:");
  for(int i=0; i<collection.size(); i++)
       view.printOutput((*collection[i]).toString());
}
*/

void Tracks::printOn(ostream & out) const {
  cout << "TRACKS:" << endl;
  for(vector<Track*>::size_type i=0; i<collection.size(); i++)
       cout << (*collection[i]).toString() << endl;
}

ostream & operator<<(ostream & out, const Tracks & tracks){
  tracks.printOn(out);
  return out;
}
