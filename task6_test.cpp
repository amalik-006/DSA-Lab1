#include <iostream>
#include <vector>
using namespace std;

int findMode(const vector<int>& arr);

int main()
{
    // Test Case 1: Unique mode
    vector<int> arr1 = {1, 2, 2, 3, 4, 2, 5};

    cout << "Test Case 1 - Unique mode: "
         << findMode(arr1) << endl;

    // Test Case 2: Multiple modes
    vector<int> arr2 = {1, 1, 2, 2, 3};

    cout << "Test Case 2 - Multiple modes: "
         << findMode(arr2) << endl;

    // Test Case 3: Empty array
    vector<int> arr3;

    cout << "Test Case 3 - Empty array: "
         << findMode(arr3) << endl;

    return 0;
}