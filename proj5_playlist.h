#include<iostream>
#include"song.h"
using namespace std;
class PlayList{
private:
	int size ;
	Song *songlist = new Song[size];
	int No_of_songs = 0;
	int current_song;
public:
	PlayList();
	friend int find(Song array[], int size, Song item);
	void AddSong(const Song &s);
	void DeleteSong(const Song &s);
	void playSong(const Song &s);
	void ShowAll() const;
	void play(int num = 1);
	void ShowStatus() const;
	Song operator + (Song song);
	Song operator - (Song song);
	~PlayList();
};