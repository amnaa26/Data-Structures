/*
 * Programmer : Amna(23k-0066)
 * Date : 26 aug 2024
 * Desc : You're developing a program to manage a seating chart for a conference held in a hall with multiple rows of seats. Each row has a different seat capacity. To efficiently handle the seating arrangements, you decide to use a dynamic array. Implement a C++ code that allocates memory for the seating chart and allows attendees' names to be inputted for each seat. Choose and implement the appropriate type of dynamic array for this scenario.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int rows;
    cout << "Enter the number of rows in the hall: ";
    cin >> rows;

    // Creating an array of pointers, where each pointer points to a dynamic array of strings
    string **seatingChart = new string*[rows];

    // Taking input for the number of seats for each row and allocating memory accordingly 
    int *seatsInRow = new int[rows]; 
    for (int i = 0; i < rows; i++) {
        cout << "Enter the number of seats in row " << i + 1 << ": ";
        cin >> seatsInRow[i];
        seatingChart[i] = new string[seatsInRow[i]];
    }

    // Input attendee names for each seat
    for (int i = 0; i < rows; i++) {
        cout << "Enter names for seats in row " << i + 1 << ":" << endl;
        for (int j = 0; j < seatsInRow[i]; j++) {
            cout << "Seat " << j + 1 << ": ";
            cin.ignore(); // Clear the input buffer
            getline(cin, seatingChart[i][j]);
        }
    }

    // Displaying output
    cout << "\nSeating Chart:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ":" << endl;
        for (int j = 0; j < seatsInRow[i]; j++) {
            cout << "Seat " << j + 1 << ": " << seatingChart[i][j] << endl;
        }
    }

    // Deallocate the memory
    for (int i = 0; i < rows; i++) {
        delete[] seatingChart[i]; // Delete each row's array
    }
    delete[] seatingChart; // Delete the array of pointers
    delete[] seatsInRow;   // Delete the seatsInRow array

    return 0;
}
