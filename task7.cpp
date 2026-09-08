#include <iostream>
#include <vector>
using namespace std;

using Matrix = vector<vector<int>>;

// Standard matrix multiplication
Matrix standardMultiply(const Matrix& A, const Matrix& B)
{
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

// Adds two matrices
Matrix addMatrix(const Matrix& A, const Matrix& B)
{
    int n = A.size();
    Matrix C(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];

    return C;
}

// Subtracts two matrices
Matrix subtractMatrix(const Matrix& A, const Matrix& B)
{
    int n = A.size();
    Matrix C(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];

    return C;
}

// Strassen's matrix multiplication
Matrix strassenMultiply(const Matrix& A, const Matrix& B)
{
    int n = A.size();

    // Base case
    if (n == 1)
    {
        return {{A[0][0] * B[0][0]}};
    }

    int mid = n / 2;

    Matrix A11(mid, vector<int>(mid));
    Matrix A12(mid, vector<int>(mid));
    Matrix A21(mid, vector<int>(mid));
    Matrix A22(mid, vector<int>(mid));

    Matrix B11(mid, vector<int>(mid));
    Matrix B12(mid, vector<int>(mid));
    Matrix B21(mid, vector<int>(mid));
    Matrix B22(mid, vector<int>(mid));

    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    Matrix M1 = strassenMultiply(addMatrix(A11, A22),
                                 addMatrix(B11, B22));

    Matrix M2 = strassenMultiply(addMatrix(A21, A22), B11);

    Matrix M3 = strassenMultiply(A11,
                                 subtractMatrix(B12, B22));

    Matrix M4 = strassenMultiply(A22,
                                 subtractMatrix(B21, B11));

    Matrix M5 = strassenMultiply(addMatrix(A11, A12), B22);

    Matrix M6 = strassenMultiply(subtractMatrix(A21, A11),
                                 addMatrix(B11, B12));

    Matrix M7 = strassenMultiply(subtractMatrix(A12, A22),
                                 addMatrix(B21, B22));

    Matrix C11 = addMatrix(
        subtractMatrix(addMatrix(M1, M4), M5), M7);

    Matrix C12 = addMatrix(M3, M5);

    Matrix C21 = addMatrix(M2, M4);

    Matrix C22 = addMatrix(
        subtractMatrix(addMatrix(M1, M3), M2), M6);

    Matrix C(n, vector<int>(n));

    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }

    return C;
}