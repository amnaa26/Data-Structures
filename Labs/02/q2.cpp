/*
 * Programmer : Amna(23k-0066)
 * Date : 26 aug 2024
 * Desc : Create a header file called matrix_multuply.h that takes two arrays as input and multiplies them and outputs a multiplied array.
          [HINT: Use 2D arrays to accomplish this]
*/

#include <iostream>
#include "matrix_multiply.h"

using namespace std;

int main() {
    int mat1[10][10], mat2[10][10], result[10][10];
    int r1, c1, r2, c2;
          
    cout << "Enter rows and columns for the first matrix: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns for the second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Error: The number of columns in the first matrix must equal the number of rows in the second matrix." << endl;
        return -1;
    }

    // Input elements of the first matrix
    cout << "Enter elements of the first matrix:\n";
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            cin >> mat1[i][j];
        }
    }

    // Input elements of the second matrix
    cout << "Enter elements of the second matrix:\n";
    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            cin >> mat2[i][j];
        }
    }

    multiplyMatrices(mat1, mat2, result, r1, c1, r2, c2);
    cout << "Resultant matrix after multiplication:\n";
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
