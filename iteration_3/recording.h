/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Louis Nel                              */
/*  Date:     21-SEP-2017                            */
/*                                                   */
/*  (c) 2017 Louis Nel                               */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _RECORDING_H
#define _RECORDING_H

#include <ostream>
#include <string>
#include <vector>

#include "track.h"

const int MAX_NUMBER_OF_TRACKS = 25; //max number of tracks on a recording

class Recording {
	/*
	Recording represents a musical commercial package of audio tracks
	For example a record album, CD, or single.
	*/
	public:
	Recording(const string & aTitle, 
	          const string & anArtist,
              const string & aProducer,
              const string & aYear,			  
			  const int anId = -1); 
	~Recording(void);
    int getID()const;
    string getIDString()const;
	void removeTrack(Track & aTrack);
	void addTrack(Track & track, int position);
	vector<Track*> & getTracks();
    string toString() const;
	
	private:
	string title;
	string artist;
	string producer;
	string year;
	int id;
	vector<Track*> tracks;
	vector<Track*>::iterator findPosition(Track & aTrack);
	Recording(const Recording & aRecording); //hide copy constructor in private section	
};

ostream & operator<<(ostream & out, const Recording & aRecording);

#endif