#include <iostream>
using namespace std;

void moveZerosOptimal(int arr[], int n)
{
    int first = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            first = i;
            break;
        }
    }
    if (first == -1)
        return;

    for (int j = first + 1; j < n; j++)
    {
        if (j != 0)
        {
            swap(arr[j], arr[first]);
            first++;
            j++;
        }
    }
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    moveZerosOptimal(arr, n);

    cout << "Printing After Zero Move to End :";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
