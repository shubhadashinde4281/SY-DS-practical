#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

void inputStudent(Student *s) {
    cout << "Enter Roll Number: ";
    cin >> s->rollNo;

    cout << "Enter Name: ";
    cin >> s->name;

    cout << "Enter Marks: ";
    cin >> s->marks;
}

void displayStudent(Student *s) {
    cout << "\nRoll Number: " << s->rollNo;
    cout << "\nName: " << s->name;
    cout << "\nMarks: " << s->marks << endl;
}

void displayAll(Student *s, int n) {
    cout << "\n========== Student Records ==========\n";

    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1;
        displayStudent(s + i);
    }
}

void searchStudent(Student *s, int n, int rollNo) {
    for (int i = 0; i < n; i++) {
        if ((s + i)->rollNo == rollNo) {
            cout << "\nStudent Found!";
            displayStudent(s + i);
            return;
        }
    }

    cout << "\nStudent with Roll Number "
         << rollNo << " not found.\n";
}

void updateStudent(Student *s, int n, int rollNo) {
    for (int i = 0; i < n; i++) {
        if ((s + i)->rollNo == rollNo) {
            cout << "\nEnter new marks: ";
            cin >> (s + i)->marks;

            cout << "Student record updated successfully!\n";
            return;
        }
    }

    cout << "\nStudent with Roll Number "
         << rollNo << " not found.\n";
}

int main() {
    Student students[100];
    int n, choice, rollNo;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        inputStudent(&students[i]);
    }

    do {
        cout << "\n\n===== Student Record Management =====";
        cout << "\n1. Display All Students";
        cout << "\n2. Search Student";
        cout << "\n3. Update Student Marks";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAll(students, n);
                break;

            case 2:
                cout << "Enter Roll Number to search: ";
                cin >> rollNo;
                searchStudent(students, n, rollNo);
                break;

            case 3:
                cout << "Enter Roll Number to update: ";
                cin >> rollNo;
                updateStudent(students, n, rollNo);
                break;

            case 4:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}