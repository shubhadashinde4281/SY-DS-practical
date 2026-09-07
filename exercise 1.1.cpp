#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {
    Student students[100];
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";

        cout << "Roll Number: ";
        cin >> students[i].rollNo;

        cout << "Name: ";
        cin >> students[i].name;

        cout << "Marks: ";
        cin >> students[i].marks;
    }

    cout << "\n========== Student Records ==========\n";
    cout << "Roll No\t\tName\t\tMarks\n";
    cout << "-----------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << students[i].rollNo << "\t\t"
             << students[i].name << "\t\t"
             << students[i].marks << endl;
    }

    return 0;
}