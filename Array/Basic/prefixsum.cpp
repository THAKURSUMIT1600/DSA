#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> prefixsum(arr.size());
    prefixsum[0] = arr[0];
    for (int i = 1; i < prefixsum.size(); i++) {
        prefixsum[i] = arr[i] + prefixsum[i - 1];
    }
    cout << "Prefix Sum :";
    for (int i = 0; i < prefixsum.size(); i++) {
        cout << prefixsum[i] << " ";
    }
    cout << endl;

    return 0;
}