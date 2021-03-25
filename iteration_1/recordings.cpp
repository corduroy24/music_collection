/*Emmanuel Dairo 101010678
  Korede Adegboye 101001124
  Date: Sept.31/17
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "recordings.h"
#include "recording.h"

Recordings::Recordings(){
}
Recordings::~Recordings(void){
	for(vector<Recording*>::size_type i=0; i<collection.size(); i++)
		delete collection[i]; //delete recordings in this container
}
vector<Recording*>::iterator Recordings::findPosition(Recording & aRecording){
	for (vector<Recording*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if(*it == &aRecording) return it;
	return collection.end();
}
Recording * Recordings::findByID(int anID){
	for (vector<Recording*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if((*it)->getID() == anID) return *it;
	return NULL;
}
void Recordings::add(Recording & aRecording){
	collection.push_back(&aRecording);
}
void Recordings::remove(Recording & aRecording){
	vector<Recording*>::iterator index = findPosition(aRecording);
	if(index != collection.end()) {
		Recording * theRecording = *index;
		collection.erase(index);
		delete theRecording; //free the memory of theRecording
	}
}
/*
void Recordings::showOn(UI & view) const {
  view.printOutput("RECORDINGS:");
  for(int i=0; i<collection.size(); i++)
       view.printOutput((*collection[i]).toString());
}
*/

void Recordings::printOn(ostream & out) const {
  cout << "RECORDINGS:" << endl;
  for(vector<Recording*>::size_type i=0; i<collection.size(); i++)
       cout << (*collection[i]).toString() << endl;
}

ostream & operator<<(ostream & out, const Recordings & Recordings){
  Recordings.printOn(out);
  return out;
}
