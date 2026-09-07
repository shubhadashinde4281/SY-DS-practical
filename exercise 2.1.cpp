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

void deleteEmployee(Employee*& head) {
    int id;

    cout << "\nEnter Employee ID to delete: ";
    cin >> id;

    Employee* temp = head;
    Employee* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "\nEmployee not found!";
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    }
    else {
        prev->next = temp->next;
    }

    delete temp;

    cout << "\nEmployee deleted successfully!";
}

void displayEmployees(Employee* head) {
    if (head == NULL) {
        cout << "\nNo employee records!";
        return;
    }

    Employee* temp = head;

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
    int choice;

    do {
        cout << "\n\n===== Employee Management System =====";
        cout << "\n1. Insert Employee";
        cout << "\n2. Delete Employee";
        cout << "\n3. Display Employees";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertEmployee(head);
                break;

            case 2:
                deleteEmployee(head);
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
