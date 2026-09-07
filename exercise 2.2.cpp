#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    float salary;
    Employee* next;
};

void insertEmployee(Employee*& head) {
    Employee* newNode = new Employee;

    cout << "\nEnter Employee ID: ";
    cin >> newNode->id;

    cout << "Enter Employee Name: ";
    cin >> newNode->name;

    cout << "Enter Salary: ";
    cin >> newNode->salary;

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Employee* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "\nEmployee inserted successfully!";
}

void searchEmployee(Employee* head, int id) {
    Employee* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            cout << "\nEmployee Found!";
            cout << "\nEmployee ID: " << temp->id;
            cout << "\nName       : " << temp->name;
            cout << "\nSalary     : " << temp->salary << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "\nEmployee with ID " << id << " not found!";
}

void displayEmployees(Employee* head) {
    Employee* temp = head;

    if (head == NULL) {
        cout << "\nNo employee records!";
        return;
    }

    cout << "\n========== Employee Records ==========\n";

    while (temp != NULL) {
        cout << "\nEmployee ID: " << temp->id;
        cout << "\nName       : " << temp->name;
        cout << "\nSalary     : " << temp->salary;
        cout << "\n--------------------------";

        temp = temp->next;
    }
}

int main() {
    Employee* head = NULL;
    int choice, id;

    do {
        cout << "\n\n===== Employee Management System =====";
        cout << "\n1. Insert Employee";
        cout << "\n2. Search Employee";
        cout << "\n3. Display Employees";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertEmployee(head);
                break;

            case 2:
                cout << "\nEnter Employee ID to search: ";
                cin >> id;
                searchEmployee(head, id);
                break;

            case 3:
                displayEmployees(head);
                break;

            case 4:
                cout << "\nExiting program...";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while (choice != 4);

    return 0;
}