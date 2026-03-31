#include "../include/Song.h"

Song::Song()
{
    title = "";
    artist = "";
    year = 0;
}

Song::Song(const string& newTitle, const string& newArtist, int newYear)
{
    title = newTitle;
    artist = newArtist;
    year = newYear;
}

string Song::getTitle() const
{
    return title;
}

string Song::getArtist() const
{
    return artist;
}

int Song::getYear() const
{
    return year;
}

void Song::setTitle(const string& newTitle)
{
    title = newTitle;
}

void Song::setArtist(const string& newArtist)
{
    artist = newArtist;
}

void Song::setYear(int newYear)
{
    year = newYear;
}

void Song::display(ostream& out) const
{
    out << "Title: " << title
        << ", Artist: " << artist
        << ", Year: " << year;
}

bool Song::operator<(const Song& rhs) const
{
    return title < rhs.title;
}

bool Song::operator==(const Song& rhs) const
{
    return title == rhs.title;
}