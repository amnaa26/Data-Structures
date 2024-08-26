/*
 * Programmer : Amna(23k-0066)
 * Date : 26 aug 2024
 * Desc : Implement Jagged arrays from the above pseudocode by taking a size of 5 and resizing it to 10 in each index.
*/


#include <iostream>
using namespace std;

int main() {
    // Creating a jagged array with 5 rows
    int* jaggedArray[5];
    int rowSize[5]; // Array to store the size of each row

   
    for (int i = 0; i < 5; i++) {
        cout << "Enter the size of row " << i + 1 << ": ";
        cin >> rowSize[i];  
        jaggedArray[i] = new int[rowSize[i]];  

    
        for (int j = 0; j < rowSize[i]; j++) {
            cout << "Enter element " << j + 1 << " for row " << i + 1 << ": ";
            cin >> jaggedArray[i][j];
        }
    }

    
    cout << "\nOriginal Jagged Array:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < rowSize[i]; j++) {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    // Resizing each row to have 10 elements
    cout << "\nResizing rows to 10 elements..." << endl;
    for (int i = 0; i < 5; i++) {
        int* newRow = new int[10];  // Allocate new row with size 10

        // Copy the existing elements to the new row
        for (int j = 0; j < rowSize[i]; j++) {
            newRow[j] = jaggedArray[i][j];
        }

       
        for (int j = rowSize[i]; j < 10; j++) {
            newRow[j] = 0;  
        }

        // Deallocate the old row and assign the new row
        delete[] jaggedArray[i];
        jaggedArray[i] = newRow;

        // Update the row size
        rowSize[i] = 10;
    }

    // Printing the resized jagged array
    cout << "\nResized Jagged Array:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < rowSize[i]; j++) {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    // Deleting dynamically allocated memory
    for (int i = 0; i < 5; i++) {
        delete[] jaggedArray[i];
    }

    return 0;
}

