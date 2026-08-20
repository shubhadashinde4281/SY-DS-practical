#include <iostream>
#include <string>
using namespace std;

struct Song
{
    string title;
    Song* prev;
    Song* next;

    Song(string t)
    {
        title = t;
        prev = NULL;
        next = NULL;
    }
};

class Playlist
{
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    Playlist()
    {
        head =  NULL;
        tail = NULL;
        current = NULL;
    }

   
    void addSong(string title)
    {
        Song* newSong = new Song(title);

        if (head == NULL)
        {
            head = tail = current = newSong;
        }
        else
        {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }

      
    }

    void nextSong()
    {
        if (current == NULL)
        {
            cout << "Playlist is empty." << endl;
        }
        else if (current->next == NULL)
        {
            cout << "Already at the last song." << endl;
        }
        else
        {
            current = current->next;
            cout << "Playing: " << current->title << endl;
        }
    }

    void previousSong()
    {
        if (current == NULL)
        {
            cout << "Playlist is empty." << endl;
        }
        else if (current->prev == NULL)
        {
            cout << "Already at the first song." << endl;
        }
        else
        {
            current = current->prev;
            cout << "Playing: " << current->title << endl;
        }
    }

    void displayForward()
    {
        Song* temp = head;

        cout << "\nForward: ";

        while (temp != NULL)
        {
            cout << temp->title;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }

    void displayBackward()
    {
        Song* temp = tail;

        cout << "Backward: ";

        while (temp != NULL)
        {
            cout << temp->title;

            if (temp->prev !=NULL)
                cout << " -> ";

            temp = temp->prev;
        }

        cout << endl;
    }

   
    void showCurrent()
    {
        if (current == NULL)
        {
            cout << "No song is currently playing." << endl;
        }
        else
        {
            cout << "Currently playing: "
                 << current->title << endl;
        }
    }

   
    ~Playlist()
    {
        Song* temp = head;

        while (temp != NULL)
        {
            Song* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main()
{
    Playlist playlist;

    
    playlist.addSong("Shape of You");
    playlist.addSong("Blinding Lights");
    playlist.addSong("Believer");
    playlist.addSong("Perfect");

   
    playlist.displayForward();

    playlist.showCurrent();

    playlist.nextSong();
    playlist.nextSong();

    playlist.previousSong();

    playlist.displayForward();
    playlist.displayBackward();

    return 0;
}
