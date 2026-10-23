#include <iostream>
using namespace std;

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = a[high];
        int i = low - 1, j, temp;

        for (j = low; j < high; j++)
        {
            if (a[j] <= pivot)
            {
                i++;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        int p = i + 1;

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    int salary[100], n, i;

    cout << "Enter number of employees: ";
    cin >> n;

    cout << "Enter employee salaries:\n";
    for (i = 0; i < n; i++)
        cin >> salary[i];

    quickSort(salary, 0, n - 1);

    cout << "Salaries in ascending order:\n";
    for (i = 0; i < n; i++)
        cout << salary[i] << " ";

    return 0;
}
