/*
 * Programmer : Amna(23k-0066)
 * Date : 26 aug 2024
 * Desc : You are tasked with developing a program to manage and display the Grade Point Average (GPA) for the core courses offered in the first semester of four departments: Software Engineering (SE), Artificial Intelligence(AI), Computer Science (CS), and Data Science (DS). Each department offers a distinct number of core courses for this semester: SE has 3 core courses, AI has 4 core courses, CS has 2 core courses, and DS has 1 core course.
          To efficiently store and present this data, which type of array structure would you employ? implement a solution using the chosen array structure to display the GPAs of the core courses for each department.
*/

#include <iostream>
#include <iomanip>

#define DEPARTMENTS 4
using namespace std;

int main() {
    int courses[DEPARTMENTS] = {3, 4, 2, 1}; // SE, AI, CS, DS

    // Creating a jagged array to store the GPA for each course in each department
    float *gpa[DEPARTMENTS];
    for (int i = 0; i < DEPARTMENTS; i++) {
        gpa[i] = new float[courses[i]];
    }

    cout << "Enter the GPA for the core courses of each department:" << endl;
    for (int i = 0; i < DEPARTMENTS; i++) {
        cout << "Department " << i + 1 << " (Number of core courses: " << courses[i] << "):" << endl;
        for (int j = 0; j < courses[i]; j++) {
            cout << "Enter GPA for course " << j + 1 << ": ";
            cin >> gpa[i][j];
        }
    }

    cout << "\nGPAs for the core courses of each department:" << endl;
    for (int i = 0; i < DEPARTMENTS; i++) {
        cout << "Department " << i + 1 << " GPAs:" << endl;
        for (int j = 0; j < courses[i]; j++) {
            cout << "Course " << j + 1 << ": " << fixed << setprecision(2) << gpa[i][j] << endl;
        }
        cout << endl;
    }

    // Deallocating the memory
    for (int i = 0; i < DEPARTMENTS; i++) {
        delete[] gpa[i];
    }

    return 0;
}


