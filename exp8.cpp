#include <iostream>
using namespace std;

int main()
{
    int id, i, choice;
    int books[5] = {101, 102, 103, 104, 105};
    int found = 0;

    cout << "LIBRARY MANAGEMENT SYSTEM\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter Book ID: ";
    cin >> id;

    if (choice == 1)
    {
        for (i = 0; i < 5; i++)
        {
            if (books[i] == id)
            {
                cout << "Book Found!\n";
                cout << "Book ID: " << books[i] << endl;
                found = 1;
                break;
            }
        }
    }
    else if (choice == 2)
    {
        int low, high, mid;

        low = 0;
        high = 4;

        while (low <= high)
        {
            mid = (low + high) / 2;

            if (books[mid] == id)
            {
                cout << "Book Found!\n";
                cout << "Book ID: " << books[mid] << endl;
                found = 1;
                break;
            }
            else if (books[mid] < id)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    else
    {
        cout << "Invalid choice!\n";
        return 0;
    }

    if (found == 0)
    {
        cout << "Book Not Found!\n";
    }

    return 0;
}
