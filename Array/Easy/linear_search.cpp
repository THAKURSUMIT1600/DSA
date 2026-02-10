#include <iostream>
#include <vector>
using namespace std;

void linearsearch(vector<int> &arr, int value)
{
    bool found = false;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == value)
        {
            cout << "Element Found at Index : " << i << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "Element not found" << endl;
    }
}

int main()
{
    cout << "Welcome to Linear Search Program\n";

    vector<int> arr;
    int n;

    cout << "Enter the Array Size: ";
    cin >> n;

    cout << "Enter the Array Elements:\n";
    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Enter element " << i << ": ";
        cin >> value;
        arr.push_back(value);
    }

    cout << "Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int value;
    cout << "Enter the Element to Searched :";
    cin >> value;
    linearsearch(arr, value);

    return 0;
}
