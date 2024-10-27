#include <iostream>
#include <vector>
using namespace std;

//getting max value existing in the array
int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}

void countingSort(vector<int>& arr, int exp, bool ascending) {
    int n = arr.size();
    vector<int> output(n); // dynamic array to store the sorted numbers
    int count[10] = {0}; // array to store occurrences of each digit (0-9)

    // counting the occurrences of each digit at exp place
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    if (ascending) {
        //ascending
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
    } else {
        //descending
        for (int i = 8; i >= 0; i--) {
            count[i] += count[i + 1];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}



void radixSort(vector<int>& arr, bool ascending) {
    int maxVal = getMax(arr);

    //exp represents 1, 10, 100...
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp, ascending);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Original Array:" << endl;
    printArray(arr);

    radixSort(arr, true);
    cout << "\nSorted Array in Ascending Order:" << endl;
    printArray(arr);

    radixSort(arr, false);
    cout << "\nSorted Array in Descending Order:" << endl;
    printArray(arr);
}
