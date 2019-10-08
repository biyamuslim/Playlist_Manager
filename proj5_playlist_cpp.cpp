#include<iostream>
#include<conio.h>
#include"proj5_playlist.h"
#include"song.h"

using namespace std;

int find(Song array[], int size, Song item){
	int index=-1;
	for (int i = 0; i <= size; i++){
		if (array[i] == item){
			index = i;
		}
	}
	return index;
};

PlayList::PlayList(){
	size = 2;
};
void PlayList::AddSong(const Song &s){
	if (find(songlist, No_of_songs, s) != -1){
		cout << "This song already exists in your playlist. " << endl;
	}
	else{
		No_of_songs++;
		songlist[No_of_songs] = s;
		if (size == No_of_songs){
			size = 2 * size;
		}
		cout << "The Song has been successfully added to your playlist. " << endl;
	}
};
void PlayList::DeleteSong(const Song &s){
	int n;
	n = find(songlist, No_of_songs, s);
	if (n == -1){
		cout << "Error : SONG NOT FOUND !" << endl;
	}
	else{
		while (n <= No_of_songs)
		{
			songlist[n] = songlist[n + 1];
			n++;
		}
		No_of_songs--;
		if (No_of_songs > 2 && No_of_songs < size/2){
				if (size % 2 == 0){
					size = size / 2;
				}
				else{
					size = (size++) / 2;
				}
			}
		cout << "The song has been successfully deleted from your playlist." << endl;
	}
};
/*void PlayList::playSong(const Song &s){
current_song = find(songlist, No_of_songs, s);
cout << songlist[current_song];
};*/
void PlayList::ShowAll() const{
	for (int ind = 1; ind <= No_of_songs; ind++){
		cout << songlist[ind] << endl;
	}
};
void PlayList::play(int num){

	current_song = num;
		cout << songlist[current_song];
		current_song++;
		if (current_song = No_of_songs+1){
			current_song = 1;
		}
	
};
void PlayList::ShowStatus() const{
	cout << "The number of songs in the list are : " << No_of_songs << endl;
	cout << "The size of list is : " << size << endl;
	cout << "The currently playing song is : " << songlist[current_song] << endl;
};
Song PlayList::operator + (Song song){
	No_of_songs++;
	songlist[No_of_songs] = song;
	return songlist[No_of_songs];
};
Song PlayList::operator - (Song song){
	int i = find(songlist, No_of_songs, song);
	if (i == -1){
		cout << " => Error : Song not found ! " << endl;
	}
	else{
		while (i < No_of_songs){
			songlist[i] = songlist[i + 1];
			i++;
		}
	}
return songlist[i];
};
PlayList::~PlayList(){
	delete songlist;
}
int playlist_menu(){
	int men;
	do{
		cout << "\n==============================================================================\n";
		cout << "                            ==  PLAYLIST MENU  ==\n";
		cout << "==============================================================================\n\n";
		cout << " 1. Play a Song \n 2. Add a song \n 3. Delete a song \n 4. Show All songs \n 5. Show status of playlist \n"
			<< " 6. Next Song \n 7. Prvious song \n 8. Exit Playlist\n\n";
		cout << "Enter the option number : ";
		cin >> men;
		if (men > 7 || men < 1)
		{
			cout << "Please select number from 1 to 8 " << endl;
		}
	} while (men<1 || men>7);
	return men;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	int ch,n;
	PlayList MyFav;
	Song s1;
	do{
		ch = playlist_menu();
		if (ch == 1){
			cout << "	________________________________" << endl;
			cout << "		*** NOW PLAYING ***" << endl;
			cout << "Enter the number of song to play : ";
			cin >> n;
			cout << "Press 0";
			MyFav.play(n);
		}
		else if (ch == 2){
			cout << "	_______________________________" << endl;
			cout << "		*** ADD SONG ***" << endl;
			cout << "Enter the details of the song (i.e. song,artist) : ";
			cin >> s1;
			MyFav.AddSong(s1);
		}
		else if (ch == 3){
			cout << "	_________________________________" << endl;
			cout << "		*** DELETE SONG ***" << endl;
			cout << "Enter the details of the song to delete (i.e. song, artist) : ";
			cin >> s1;
			MyFav.DeleteSong(s1);
		}
		else if (ch == 4){
			cout << "	_______________________________" << endl;
			cout << "		*** ALL SONGS ***" << endl;
			MyFav.ShowAll();
		}
		else if (ch == 5){
			cout << "	_____________________________________" << endl;
			cout << "		*** PLAYLIST STATUS ***" << endl;
			MyFav.ShowStatus();
		}
		else if (ch == 6){
			cout << "	_______________________________" << endl;
			cout << "		*** NEXT SONG ***" << endl;
			MyFav.play();
		}
		else if (ch == 7){
			cout << "	____________________________________" << endl;
			cout << "		*** PREVIOUS SONG ***" << endl;

		}
		else if (ch == 8){
			cout << "	Have a good day." << endl;
		}
	} while (ch != 8);
	_getch();
return 0;
}
