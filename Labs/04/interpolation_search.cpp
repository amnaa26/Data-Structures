#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23};  
    int size = sizeof(arr) / sizeof(arr[0]);
    int search = 18;  // Element to search

    int low = 0, high = size - 1, pos;

    while (low <= high && search >= arr[low] && search <= arr[high]) {
        if (low == high) {
            if (arr[low] == search) {
                cout << "Element found at index: " << low;
            } else {
                cout << "Element not found.";
            }
            return 0;
        }

        // formula
        pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (search - arr[low]));
        if (arr[pos] == search) {
            cout << "Element found at index: " << pos;
            return 0;
        }

        if (arr[pos] < search) {
            low = pos + 1;
        }else {
            high = pos - 1;
        }
    }

    cout << "Element not found.";
    return 0;
}
