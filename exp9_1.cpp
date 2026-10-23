#include <iostream>
using namespace std;

int main()
{
    int marks[100], n, i, j, temp;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter student marks:\n";
    for (i = 0; i < n; i++)
    {
        cin >> marks[i];
    }

    // Ascending order
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (marks[j] > marks[j + 1])
            {
                temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }

    cout << "\nMarks in Ascending Order:\n";
    for (i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }

    // Descending order
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (marks[j] < marks[j + 1])
            {
                temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }

    cout << "\n\nMarks in Descending Order:\n";
    for (i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }

    return 0;
}
