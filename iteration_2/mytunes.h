/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Contributors:   Korede Adegboye 101001124        */
/* 									Emmanuel Dairo 101010678   			 */
/*									Louis Nel												 */
/*  Date:     NOV-2017                               */
/*                                                   */
/*  (c) Nov 2017                                     */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MYTUNES_H
#define MYTUNES_H
#include <sstream>
using namespace std;
#include "UI.h"
#include "command.h"
#include "song.h"
//#include "songs.h"
#include "recording.h"
//#include "recordings.h"
#include "track.h"
//#include "tracks.h"
#include "playlist.h"
#include "user.h"
//#include "users.h"
#include "mytunes_collection.h"

/*
This is the main application class.
It has knowlege of the UI and data model (not done in this assignment).
*/

class MyTunes
{
  public:
    MyTunes();
    void run();
    void executeCommand(Command cmd);
  private:
    UI view;
	//Data Model
	//available ID's for app assigned ID's
	//These should only be used after database data has loaded
	int nextAvailableSongID;
	int nextAvailableRecordingID;
	int nextAvailableTrackID;
	//Data collections
	MyTunesCollection <Song> songs;
	MyTunesCollection <Recording> recordings;
	MyTunesCollection  <Track> tracks;
	MyTunesCollection <User> users;

    void executeCMDADD(Command cmd);
    void executeCMDDELETE(Command cmd);
    void executeCMDSHOW(Command cmd);

	void executeAddSong(Command cmd);
	void executeAddRecording(Command cmd);
	void executeAddTrack(Command cmd);
	void executeAddUser(Command cmd);
	void executeAddPlaylist(Command cmd);
	void executeAddPlaylistTrack(Command cmd);

	void executeDeleteRecording(Command cmd);
	void executeDeleteUser(Command cmd);
    void executeDeleteUserPlaylist(Command cmd);
    void executeDeleteUserPlaylistTrack(Command cmd);
	void executeDeleteTrack(Command cmd); //cascading delete
	void executeDeleteSong(Command cmd);

};
#endif
