//Music playlist

#include <iostream>
#include <string>
using namespace std;

class MusicPlayer
{
private:
    string playlist[10];
    int count;
    string currentlyPlayingSong;

public:
    MusicPlayer()
    {
        count = 0;
        currentlyPlayingSong = "";
    }
    void addsong(string name)
    {
        if (count < 10)
        {
            playlist[count] = name;
            count++;
            cout << "\"" << name << "\" added to playlist.\n";
        }
        else
        {
            cout << "Playlist is full! Cannot add more songs.\n";
        }
    }

    void removesong(string name)
    {
        int index = -1;
        for (int i = 0; i < count; i++)
        {
            if (playlist[i] == name)
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            for (int i = index; i < count-1; i++)
            {
                playlist[i] = playlist[i + 1];
            }
            count--;
            cout << "\"" << name << "\" removed from playlist.\n";
        }
        else
        {
            cout << "Song not found.\n";
        }
    }
    void playsong(string name)
    {
        for (int i = 0; i < count; i++)
        {
            if (playlist[i] == name)
            {
                currentlyPlayingSong = name;
                cout << "Now playing: \"" << name << "\"\n";
                return;
            }
        }
        cout << "Song not found in playlist!\n";
    }
    void showplaylist()
    {
        if (count==0)
        {
            cout << "No songs added in Playlist!\n";
            return;
        }
        cout << "Playlist: " << endl;
        for (int i = 0; i < count; i++)
        {
            cout << playlist[i] << endl;
        }
    }
};

int main()
{
    MusicPlayer immy;
    immy.showplaylist();
    immy.addsong("Qaumi Tarana");
    immy.playsong("Haye Haye Oye Hoye");
    immy.addsong("Sohni Dharti");
    immy.addsong("Wheels on the bus");
    immy.playsong("Sohni Dharti");
    immy.removesong("Baba BlackSheep");
    immy.showplaylist();
    return 0;
}
