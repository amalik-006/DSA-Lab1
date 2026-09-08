#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generatePascalsTriangle(int n);

void displayTriangle(const vector<vector<int>>& triangle)
{
    for (const auto& row : triangle)
    {
        for (int value : row)
            cout << value << " ";

        cout << endl;
    }
}

int main()
{
    // Test Case 1: n = 0
    cout << "Test Case 1 - n = 0:" << endl;
    displayTriangle(generatePascalsTriangle(0));

    // Test Case 2: n = 1
    cout << "\nTest Case 2 - n = 1:" << endl;
    displayTriangle(generatePascalsTriangle(1));

    // Test Case 3: n = 5
    cout << "\nTest Case 3 - n = 5:" << endl;
    vector<vector<int>> triangle = generatePascalsTriangle(5);
    displayTriangle(triangle);

    // Verify row 5
    cout << "\nVerification of row 5: ";
    if (triangle.size() >= 5 &&
        triangle[4] == vector<int>{1, 4, 6, 4, 1})
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;
    }

    return 0;
}