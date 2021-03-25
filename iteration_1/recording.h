#ifndef _RECORDING_H
#define _RECORDING_H

#include <ostream>
#include <string>

class Recording {
	/*
	Song represents a musical composition (not an audio recording)
	*/
	public:
	Recording(const string & aTitle, const string & aArtist, const string & aProducer, const int aYear, const int anId = -1);
	Recording(const Recording & aRecording);
	Recording & operator=(const Recording & aRecording);

	~Recording(void);
    int getID();
    string toString() const;

	private:
	string title;
	string producer;
  string artist;
  int year;
	int AId;
};

ostream & operator<<(ostream & out, const Recording & aRecording);

#endif
