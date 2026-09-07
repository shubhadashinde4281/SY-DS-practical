#include <iostream>
#include <string>
using namespace std;

struct Song {
    string name;
    Song* prev;
    Song* next;
};

void addSong(Song*& head) {
    Song* newSong = new Song;

    cout << "\nEnter Song Name: ";
    cin >> newSong->name;

    newSong->prev = NULL;
    newSong->next = NULL;

    if (head == NULL) {
        head = newSong;
    }
    else {
        Song* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newSong;
        newSong->prev = temp;
    }

    cout << "\nSong added successfully!";
}

void displayForward(Song* head) {
    if (head == NULL) {
        cout << "\nPlaylist is empty!";
        return;
    }

    Song* temp = head;

    cout << "\n===== Forward Playlist =====\n";

    while (temp != NULL) {
        cout << temp->name << endl;
        temp = temp->next;
    }
}

void displayBackward(Song* head) {
    if (head == NULL) {
        cout << "\nPlaylist is empty!";
        return;
    }

    Song* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "\n===== Backward Playlist =====\n";

    while (temp != NULL) {
        cout << temp->name << endl;
        temp = temp->prev;
    }
}

int main() {
    Song* head = NULL;
    int choice;

    do {
        cout << "\n\n===== Music Playlist =====";
        cout << "\n1. Add Song";
        cout << "\n2. Forward Navigation";
        cout << "\n3. Backward Navigation";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addSong(head);
                break;

            case 2:
                displayForward(head);
                break;

            case 3:
                displayBackward(head);
                break;

            case 4:
                cout << "\nExiting...";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while (choice != 4);

    return 0;
}