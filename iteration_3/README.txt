Emmanuel Dairo 101010678

Korede Adegboye 101001124

Date: Dec.5/17


To compile:
make clean mytunes
To run:
./mytunes

The program reads the insert_beatles_tracks_rev1.txt script on startup.
To disable this behaviour comment out the lines:

  //initialize app with input script
  Command cmd = Command(".read insert_beatles_tracks_rev1.txt");
  executeCommand(cmd);

in the run() method at the start of the UI.cpp file.

- Supports; following a playlist and stop following a playlist
- Implemented the Gamma Observer Pattern

use  ".read follow_script.txt" for tested requirements 

Using the aplication:
For help on the commands that the application, the user will be prompted with a help screen each time.


*** One memory leak was found, with the Profs provided A3 (without part 2) solution code 