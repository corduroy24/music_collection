# music_collection

## Background
A household, or group, of people, want to combine their individual CD music collections by rippring them all to mp3's and then accessing the collection with a command line app. The app should house the music collection and provide users (members) with access. A user should be able to create playlists and place selections (songs) from the music collection in their various playlists. A user should be able to search for songs and add and delete songs from their playlists or to and from the music collection as a whole. (Ultimately a user should be able to play song selections but our initial development scope will be building an app to manage the information about the songs and provide access to that).

The client has tried some commercial mp3 players (e.g. itunes, amazing slow downer, anytunes etc.) and found them all to be unsatisfactory. Here are some of the "deal breakers" with other apps that should be addressed in this development.

1) A user should be able to add and remove songs by way of the playlists and not just a by way of a global songs collection. When you delete a song from a playlist it should be, optionally, possible to delete it from the entire collection as well.

2) Searching for songs should not be encumbered by case or punctuation in song titles or CD titles. One should be able to search based on partial information about titles, names etc.

3) A user should be able to script commands and run them from a file and not just execute them one by one interactively on the command line interface.

4) A user should be able to log the commands and repsonses and save them as a record (or audit) of a session with the app.

## Iteration 1 
Design and implement the command language and "front end" command line interface that the user will use to operate the application. One of the requirements is that commands can be read from a script file and executed one at a time. Thus along with your code you need to submit two scripts that use the language that you design. One script should be the commands that would enter all the data from the beatles.db data set into your app. The other a script that illustrates that the functional requirements for the language have been met. Note we are only designing the front end here so we will not actually represent the data inside the app yet.

This iteration implements the in-memory data model and then fully implement the commands to have them operate on the in-memory data. This is when commands are executed the appropriate data objects of type Song, Recording, Track, User, or Playlist will be created and the appropriate relationships establised by adding the object to the proper container or establishing the reference or pointer links that are needed. The "display" commands actually show what is currently in the data model.

The application will be initialized by the script and accounts for all the data in the beatles.db database and contain whatever other data is required to illustrate the operation of your commands on the actual data.

## Iteration 2

This development phase is a refactoring of code (Template-based of Application Containers)

## Iteraation 3

Added a new functional capability to the code developed from iteration 1 and based on the Gamma Observer Pattern.

**Scenario:**

A group of musicians have seen our playlist app and want to use it to manage their setlists during rehearsals and performances. Setlists are lists of songs that are meant to be performed together. They intend use our playlists as their setlists. (From here on we will use the terms setlist and playlist interchangeably.)

The musicians often have a situation where one band member makes changes to a setlist that must be reflected in the same setlist of other members. In this scenario each musician (user) has their own copy of a setlist. So they want the application to be modified so that band members can have their setlists following the changes made to another member's setlist. The new feature that they have requested is a command and behaviour that lets band members have their setlists follow the contents of another member's setlist. They want you to implement the following new command (or your version of the command based on your applications language).

