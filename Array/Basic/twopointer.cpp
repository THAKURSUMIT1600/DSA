#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = { /* your array here */ };
    int n = arr.size();

    int left = 0;          // start pointer
    int right = n - 1;     // end pointer

    while (left < right) {
        // Access current elements
        int a = arr[left];
        int b = arr[right];

        // Condition to check / operation
        // Example: if (a + b == target) { ... }

        // Move pointers based on some condition
        // left++;  // move left pointer forward
        // right--; // move right pointer backward
    }

    return 0;
}
