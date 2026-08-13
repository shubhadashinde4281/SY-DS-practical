#include <iostream>
#include <string>

using namespace std;

struct Employee
{
    int employeeId;
    string employeeName;
    float salary;
    Employee *next;
};

Employee *head = NULL;

void insert()
{
    Employee *newNode = new Employee;

    cout << "Enter Employee ID: ";
    cin >> newNode->employeeId;

    cout << "Enter Employee Name: ";
    cin >> newNode->employeeName;

    cout << "Enter Employee Salary: ";
    cin >> newNode->salary;

    newNode->next = head;
    head = newNode;

    cout << "Employee Record Inserted Successfully.\n";
}

void deleteNode(int id)
{
    if (head == NULL)
    {
        cout << "List is Empty.\n";
        return;
    }

    Employee *temp = head;
    Employee *prev = NULL;

    if (head->employeeId == id)
    {
        head = head->next;
        delete temp;
        cout << "Employee Record Deleted Successfully.\n";
        return;
    }

    while (temp != NULL && temp->employeeId != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Employee Record Not Found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Employee Record Deleted Successfully.\n";
}

void search(int id)
{
    Employee *temp = head;

    while (temp != NULL)
    {
        if (temp->employeeId == id)
        {
            cout << "\nEmployee Found\n";
            cout << "Employee ID: " << temp->employeeId << endl;
            cout << "Employee Name: " << temp->employeeName << endl;
            cout << "Employee Salary: " << temp->salary << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Employee Record Not Found.\n";
}

void display()
{
    if (head == NULL)
    {
        cout << "List is Empty.\n";
        return;
    }

    Employee *temp = head;

    cout << "\nEmployee Records\n";
    cout << "----------------------------------------\n";

    while (temp != NULL)
    {
        cout << "ID: " << temp->employeeId;
        cout << "\tName: " << temp->employeeName;
        cout << "\tSalary: " << temp->salary << endl;

        temp = temp->next;
    }
}

int main()
{
    int choice, id;

    do
    {
        cout << "\n===== Employee Management System =====\n";
        cout << "1. Insert Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Search Employee\n";
        cout << "4. Display Employees\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            cout << "Enter Employee ID to Delete: ";
            cin >> id;
            deleteNode(id);
            break;

        case 3:
            cout << "Enter Employee ID to Search: ";
            cin >> id;
            search(id);
            break;

        case 4:
            display();
            break;

        case 5:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
