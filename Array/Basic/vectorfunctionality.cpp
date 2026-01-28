#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "Welcome to Array Game" << endl;

    int size;
    cout << "Enter the array size: ";
    cin >> size;

    vector<int> arr;        // dynamic array
    arr.reserve(size);      // optional: limit capacity

    int option;

    while (true) {
        cout << "\nSelect the Following Option\n";
        cout << "Press 1 for Inserting element\n";
        cout << "Press 2 for Deleting element\n";
        cout << "Press 3 for Updating element\n";
        cout << "Press 4 for Printing element\n";
        cout << "Press 5 for Exit\n";
        cin >> option;

        // INSERT
        if (option == 1) {
            cout << "Insert operation selected\n";

            int pos, value;
            cout << "Enter the Position: ";
            cin >> pos;

            if (pos < 0 || pos > arr.size() || arr.size() == size) {
                cout << "Invalid Position or Array Full!" << endl;
            } else {
                cout << "Enter the Value: ";
                cin >> value;

                arr.insert(arr.begin() + pos, value);
                cout << "Element Inserted!" << endl;
            }
        }

        // DELETE
        else if (option == 2) {
            cout << "Delete operation selected\n";

            int pos;
            cout << "Enter the Position: ";
            cin >> pos;

            if (pos < 0 || pos >= arr.size()) {
                cout << "Invalid Position!" << endl;
            } else {
                arr.erase(arr.begin() + pos);
                cout << "Element Deleted!" << endl;
            }
        }

        // UPDATE
        else if (option == 3) {
            cout << "Update operation selected\n";

            int pos, value;
            cout << "Enter the Position: ";
            cin >> pos;

            if (pos < 0 || pos >= arr.size()) {
                cout << "Invalid Position!" << endl;
            } else {
                cout << "Enter new value: ";
                cin >> value;
                arr[pos] = value;
                cout << "Element Updated!" << endl;
            }
        }

        // PRINT
        else if (option == 4) {
            cout << "Print operation selected\n";

            if (arr.empty()) {
                cout << "Array is Empty" << endl;
            } else {
                for (int x : arr) {
                    cout << x << " ";
                }
                cout << endl;
            }
        }

        // EXIT
        else if (option == 5) {
            cout << "Exiting Program...\n";
            break;
        }

        else {
            cout << "Invalid Option!\n";
        }
    }

    return 0;
}
