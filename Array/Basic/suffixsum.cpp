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
    vector<int> suffixsum(arr.size());
    int m = arr.size();
    suffixsum[m - 1] = arr[m - 1];
    for (int i = m - 2; i >= 0; i--) {
        suffixsum[i] = suffixsum[i + 1] + arr[i];
    }
    cout << "Suffix Sum :";
    for (int i = 0; i < suffixsum.size(); i++) {
        cout << suffixsum[i] << " ";
    }
    cout << endl;

    return 0;
}