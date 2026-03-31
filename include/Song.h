#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>
#include "SongInterface.h"
#include "Comparable.h"

using namespace std;

/*
   Song class stores one song.
   Songs are compared by title.
*/
class Song : public SongInterface, public Comparable<Song>
{
private:
    string title;
    string artist;
    int year;

public:
    Song();
    Song(const string& newTitle, const string& newArtist, int newYear);

    string getTitle() const;
    string getArtist() const;
    int getYear() const;

    void setTitle(const string& newTitle);
    void setArtist(const string& newArtist);
    void setYear(int newYear);

    void display(ostream& out) const;

    bool operator<(const Song& rhs) const;
    bool operator==(const Song& rhs) const;
};

#endif