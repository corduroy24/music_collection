#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "playlists.h"
#include "playlist.h"

Playlists::Playlists(){
}

Playlists::~Playlists(void){
	for(vector<Playlist*>::size_type i=0; i<collection.size(); i++)
		delete collection[i]; //delete playlists in this container
}
vector<Playlist*>::iterator Playlists::findPosition(Playlist & aPlaylist){
	for (vector<Playlist*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if(*it == &aPlaylist) return it;
	return collection.end();
}
Playlist * Playlists::findByID(string anID){
	for (vector<Playlist*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if((*it)->getID().compare(anID)==0) return *it;
	return NULL;
}
void Playlists::add(Playlist & aPlaylist){
	collection.push_back(&aPlaylist);
}
void Playlists::remove(Playlist & aPlaylist){
	vector<Playlist*>::iterator index = findPosition(aPlaylist);
	if(index != collection.end()) {
		Playlist * thePlaylist = *index;
		collection.erase(index);
		delete thePlaylist; //free the memory of thePlaylist
	}
}
/*
void Playlists::showOn(UI & view) const {
  view.printOutput("PLAYLISTS:");
  for(int i=0; i<collection.size(); i++)
       view.printOutput((*collection[i]).toString());
}
*/

void Playlists::printOn(ostream & out) const {
  cout << "PLAYLISTS:" << endl;
  for(vector<Playlist*>::size_type i=0; i<collection.size(); i++)
       cout << (*collection[i]).toString() << endl;
}

ostream & operator<<(ostream & out, const Playlists & playlists){
  playlists.printOn(out);
  return out;
}
