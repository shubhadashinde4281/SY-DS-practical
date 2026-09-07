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

void deleteSong(Song*& head) {
    string name;

    cout << "\nEnter Song Name to delete: ";
    cin >> name;

    Song* temp = head;

    while (temp != NULL && temp->name != name) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "\nSong not found!";
        return;
    }

    if (temp->prev == NULL) {
        head = temp->next;

        if (head != NULL) {
            head->prev = NULL;
        }
    }
    else {
        temp->prev->next = temp->next;

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }

    delete temp;

    cout << "\nSong deleted successfully!";
}

void displaySongs(Song* head) {
    if (head == NULL) {
        cout << "\nPlaylist is empty!";
        return;
    }

    Song* temp = head;

    cout << "\n========== Music Playlist ==========\n";

    while (temp != NULL) {
        cout << temp->name << endl;
        temp = temp->next;
    }
}

int main() {
    Song* head = NULL;
    int choice;

    do {
        cout << "\n\n===== Music Playlist =====";
        cout << "\n1. Add Song";
        cout << "\n2. Delete Song";
        cout << "\n3. Display Playlist";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addSong(head);
                break;

            case 2:
                deleteSong(head);
                break;

            case 3:
                displaySongs(head);
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