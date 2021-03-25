Emmanuel Dairo 101010678

Korede Adegboye 101001124

Date: Nov.16/17


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

Modified code, to implement refactoring
  - instead of indiviudal collection classes, a template was used

use "".read Part2TestScript.txt" for regression testing

Using the aplication:
For help on the commands that the application, the user will be prompted with a help screen each time.
