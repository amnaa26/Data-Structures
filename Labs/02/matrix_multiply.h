#ifndef MATRIX_MULTIPLY_H
#define MATRIX_MULTIPLY_H

void multiplyMatrices(int mat1[][10], int mat2[][10], int result[][10], int r1, int c1, int r2, int c2) {
    // Initialize the result matrix with zeros
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            for (int k = 0; k < c1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

#endif
