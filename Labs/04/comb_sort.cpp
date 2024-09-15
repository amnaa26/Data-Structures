#include <iostream>
using namespace std;

int getNextGap(int gap) {
    gap = (gap * 10) / 13; // Shrink gap by a factor of 1.3
    if (gap < 1) {
        return 1;  // Minimum gap can be 1
    }
    return gap;
}

void combSort(int arr[], int size) {
    int gap = size;  
    bool swapped = true;  
    while (gap != 1 || swapped) {
        gap = getNextGap(gap);  
        swapped = false;
        for (int i = 0; i < size - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}


int main() {
    int arr[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};  
    int size = sizeof(arr) / sizeof(arr[0]);
    combSort(arr, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
