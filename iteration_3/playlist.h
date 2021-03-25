/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Contributors:   Korede Adegboye 101001124        */
/* 									Emmanuel Dairo 101010678   			 */
/* 	Date:     DEC-2017                               */
/*                                                   */
/*  (c) Dec 2017                                     */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _Playlist_H
#define _Playlist_H

#include <ostream>
#include <string>
#include <vector>

#include "track.h"
#include "observer.h"
#include "subject.h"


class Playlist : public Observer, public Subject {
	/*
	Playlist represents an user playlist of tracks.
	*/
	public:
	Playlist(const string & aPlaylistName);
	~Playlist(void);
  int getID();
	string getName();
	void removeTrack(Track & aTrack);
	void addTrack(Track & aTrack);
	vector<Track*> & getTracks();
  string toString() const;
	void update(Subject * subject);
	//void printOn(ostream & out);
	void stopFollowing();
	void startFollowing(Playlist & aPlaylist);


	private:
	string name;
	vector<Track*> tracks;
	vector<Track*>::iterator findPosition(Track & aTrack);
	Playlist * following;  //subject playlist being followed
	Playlist(const Playlist & aPlaylist); //hide copy constructor in private section
};



ostream & operator<<(ostream & out, const Playlist & aPlaylist);

#endif
