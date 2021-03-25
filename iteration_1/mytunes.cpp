/*Emmanuel Dairo 101010678
  Korede Adegboye 101001124
  Date: Sept.31/17
*/

#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
#include "mytunes.h"
#include "UI.h"
#include "command.h"
#include <iostream>


MyTunes::MyTunes():view(this)
{
}

void MyTunes::run()
{
	//start user interface
	view.run();

}
void MyTunes::executeCommand(Command cmd){

    //execute application (non UI shell) commands
    //These are the commands that affect the data model
    //or retrieve contents from the data model
	if(cmd.isCommand(CMD_ADD)) executeCMDADD(cmd);
	else if(cmd.isCommand(CMD_DELETE)) executeCMDDELETE(cmd);
	else if(cmd.isCommand(CMD_SHOW)) executeCMDSHOW(cmd);
}

//APP COMMANDS
void MyTunes::executeCMDADD(Command cmd){
	view.printOutput("EXECUTING: " + cmd.getCommandString());

	//add song
	if(cmd.getToken(1)=="-s"){
		stringstream temp (cmd.getToken(2));
		int sid = 0;
		temp >> sid;
		Song *song = new Song(cmd.getToken(3), cmd.getToken(4), sid);
		songsCol.add(*song);
	}

// add recording
	else if(cmd.getToken(1)=="-r"){
		int year = 0;
		int id = 0;

		stringstream tempYear (cmd.getToken(6));
		tempYear >> year;

		stringstream tempID (cmd.getToken(2));
		tempID >> id;

		Recording *recording = new Recording(cmd.getToken(3), cmd.getToken(4), cmd.getToken(5), year, id);
		recsCol.add(*recording);
	}

//add user
	else if(cmd.getToken(1)=="-u"){
		User *user = new User(cmd.getToken(2), cmd.getToken(3));
		usersCol.add(*user);
	}

// add track
	else if(cmd.getToken(1)=="-t"){
		int albumID = 0;
		int trkNo = 0;
		int songID = 0;
		stringstream tempAID (cmd.getToken(2));
		tempAID >> albumID;

		stringstream tempSID (cmd.getToken(3));
		tempSID >> songID;

		stringstream tempTN (cmd.getToken(4));
		tempTN >> trkNo;

		Track *track = new Track(trkNo, songID, albumID);
		trksCol.add(*track);
	}

//add playlist
	else if(cmd.getToken(1)=="-p"){
		Playlist *playlist = new Playlist(cmd.getToken(2), cmd.getToken(3));
		plsCol.add(*playlist);
	}

}
void MyTunes::executeCMDDELETE(Command cmd){
	view.printOutput("EXECUTING: " + cmd.getCommandString());

	//delete song
	if(cmd.getToken(1)=="-s"){
		stringstream tempSID (cmd.getToken(2));
		int sid = 0;
		tempSID >> sid;
		songsCol.remove(*songsCol.findByID(sid));
	}

// delete recording
	else if(cmd.getToken(1)=="-r"){
		stringstream tempRID (cmd.getToken(2));
		int rid = 0;
		tempRID >> rid;
		recsCol.remove(*recsCol.findByID(rid));
	}

//delete user
	else if(cmd.getToken(1)=="-u"){
		usersCol.remove(*usersCol.findByID(cmd.getToken(2)));
	}

// delete track
	else if(cmd.getToken(1)=="-t"){
		stringstream tempSID (cmd.getToken(2));
		int sid = 0;
		tempSID >> sid;
		trksCol.remove(*trksCol.findBySID(sid));
	}

//delete playlist
	else if(cmd.getToken(1)=="-p"){
		plsCol.remove(*plsCol.findByID(cmd.getToken(2)));
	}


}
void MyTunes::executeCMDSHOW(Command cmd){
	view.printOutput("EXECUTING: " + cmd.getCommandString());

	//show songs
	if(cmd.getToken(1).compare("songs")==0)
		songsCol.printOn(cout);


// show recording
	else if(cmd.getToken(1).compare("recordings")==0){
		recsCol.printOn(cout);
	}

//show user
	else if(cmd.getToken(1).compare("users")==0){
		usersCol.printOn(cout);
	}

// show tracks
else if(cmd.getToken(1).compare("tracks")==0){
	trksCol.printOn(cout);
	}

//show playlist
else if(cmd.getToken(1).compare("playlists")==0){
	plsCol.printOn(cout);
	}

}
