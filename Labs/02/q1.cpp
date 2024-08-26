/*
 * Programmer : Amna(23k-0066)
 * Date : 26 aug 2024
 * Desc : Implement Jagged arrays from the above pseudocode by taking a size of 5 and resizing it to 10 in each index.
*/


#include <iostream>
using namespace std;

int main() {
    int **arr = new int*[3];  // Jagged array declaration
    int Size[3];  // Array to store the size of each row
    int i, j;

    // Getting the size of each row
    for(i = 0; i < 3; i++) {
        cout << "Row " << i + 1 << " size: ";
        cin >> Size[i];
        arr[i] = new int[Size[i]];  // Allocating memory for each row
    }

    // Getting elements for each row
    for(i = 0; i < 3; i++) {
        for(j = 0; j < Size[i]; j++) {
            cout << "Enter row " << i + 1 << " element " << j + 1 << ": ";
            cin >> arr[i][j];
        }
    }

    // Display the jagged array
    cout << "\nDisplaying the jagged array:\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < Size[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocating memory
    for(i = 0; i < 3; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
