#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

using Matrix = vector<vector<int>>;

Matrix standardMultiply(const Matrix& A, const Matrix& B);
Matrix strassenMultiply(const Matrix& A, const Matrix& B);

void printMatrix(const Matrix& matrix)
{
    for (const auto& row : matrix)
    {
        for (int value : row)
            cout << value << " ";

        cout << endl;
    }
}

bool matricesEqual(const Matrix& A, const Matrix& B)
{
    return A == B;
}

int main()
{
    // Test Case 1: 2x2 matrix multiplication
    Matrix A2 = {
        {1, 2},
        {3, 4}
    };

    Matrix B2 = {
        {5, 6},
        {7, 8}
    };

    Matrix standard2 = standardMultiply(A2, B2);
    Matrix strassen2 = strassenMultiply(A2, B2);

    cout << "Test Case 1 - 2x2 Matrix:" << endl;
    printMatrix(strassen2);

    cout << "Comparison: "
         << (matricesEqual(standard2, strassen2) ? "PASS" : "FAIL")
         << endl;

    // Test Case 2: 4x4 matrix multiplication
    Matrix A4 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    Matrix B4 = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };

    Matrix standard4 = standardMultiply(A4, B4);
    Matrix strassen4 = strassenMultiply(A4, B4);

    cout << "\nTest Case 2 - 4x4 Matrix:" << endl;
    printMatrix(strassen4);

    cout << "Comparison: "
         << (matricesEqual(standard4, strassen4) ? "PASS" : "FAIL")
         << endl;

    // Test Case 3: Random values
    srand(42);

    Matrix randomA(4, vector<int>(4));
    Matrix randomB(4, vector<int>(4));

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            randomA[i][j] = rand() % 10;
            randomB[i][j] = rand() % 10;
        }
    }

    Matrix standardRandom = standardMultiply(randomA, randomB);
    Matrix strassenRandom = strassenMultiply(randomA, randomB);

    cout << "\nTest Case 3 - Random Values:" << endl;
    cout << "Comparison: "
         << (matricesEqual(standardRandom, strassenRandom)
                 ? "PASS"
                 : "FAIL")
         << endl;

    return 0;
}