/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Contributors:   Korede Adegboye 101001124        */
/* 									Emmanuel Dairo 101010678   			 */
/* 	Date:     NOV-2017                               */
/*                                                   */
/*  (c) Nov 2017                                     */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef _MYTUNESCOLLECTION_H
#define _MYTUNESCOLLECTION_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
#include "UI.h"

template <typename T>
class MyTunesCollection {

	public:
	MyTunesCollection();
	~MyTunesCollection(void);
	T * findByID(int anID);
	T * findByID(const string & anID);

	vector<T*> getCollection();
	void add(T & aT);
	void remove(T & aT);
	void showOn(UI & aView);
	void showOn(UI & aView, int memberID);
	void showOn(UI & aView, const string & memberID);
	private:
	vector<T*> collection;
	typename vector<T*>::iterator findPosition(T & aT);
};

template <typename T>
MyTunesCollection<T>::MyTunesCollection(){
}

template <typename T>
MyTunesCollection<T>::~MyTunesCollection(void){
	for(int i=0; i<collection.size(); i++)
		delete collection[i]; //delete songs in this container
}

template <typename T>
vector<T*> MyTunesCollection<T>::getCollection(){
	return collection;
}

template <typename T>
typename vector<T*>::iterator MyTunesCollection<T>::findPosition(T & aT){
	for (typename vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if(*it == &aT) return it;
	return collection.end();
}

template <typename T>
T * MyTunesCollection<T>::findByID(int anID){
	for (typename vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if((*it)->getID() == anID) return *it;
	return NULL;
}

template <typename T>
T * MyTunesCollection<T>::findByID(const string & anID){
	for (typename vector<User*>::iterator itr = collection.begin() ; itr != collection.end(); ++itr)
		if(((*itr)->getStringID()).compare(anID) == 0) return *itr;
	return NULL;
}



template <typename T>
void MyTunesCollection<T>::add(T & aT){
	collection.push_back(&aT);
}

template <typename T>
void MyTunesCollection<T>::remove(T & aT){
	typename vector<T*>::iterator index = findPosition(aT);
	if(index != collection.end()) {
		T * theT = *index;
		collection.erase(index);
		delete theT; //free the memory of theSong
	}
}

template <typename T>
void MyTunesCollection<T>::showOn(UI & view) {
  view.printOutput("The Collection:");
  for(int i=0; i<collection.size(); i++)
       view.printOutput((*collection[i]).toString());
}

template <typename T>
void MyTunesCollection<T>::showOn(UI & view, int memberID)  {
  view.printOutput("The Collection:");
  T * t = findByID(memberID);
  if( t != NULL)
       view.printOutput(t->toString());
}

template <typename T>
void MyTunesCollection<T>::showOn(UI & view, const string & memberID) {
  view.printOutput("The Collection:");
  T * t = findByID(memberID);
  if( t != NULL)
       view.printOutput(t->toString());
}


#endif
