/*Emmanuel Dairo 101010678
  Korede Adegboye 101001124
  Date: Sept.31/17
*/

#ifndef MYTUNES_H
#define MYTUNES_H
#include <sstream>
using namespace std;
#include "UI.h"
#include "command.h"
#include "song.h"
#include "user.h"
#include "track.h"
#include "playlist.h"
#include "recording.h"
#include "songs.h"
#include "recordings.h"
#include "users.h"
#include "tracks.h"
#include "playlists.h"







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
    Songs songsCol;
    Recordings recsCol;
    Tracks trksCol;
    Users usersCol;
    Playlists plsCol;
    void executeCMDADD(Command cmd);
    void executeCMDDELETE(Command cmd);
    void executeCMDSHOW(Command cmd);
};




#endif
