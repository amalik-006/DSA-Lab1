#include <iostream>
#include <vector>
using namespace std;

vector<int> findAllIndices(const vector<int>& arr, int key);

int main()
{
    // Test Case 1: Multiple occurrences
    vector<int> arr1 = {1, 2, 3, 2, 4, 2, 5};
    vector<int> result1 = findAllIndices(arr1, 2);

    cout << "Test Case 1 - Multiple occurrences: ";
    for (int index : result1)
        cout << index << " ";
    cout << endl;

    // Test Case 2: Key not present
    vector<int> arr2 = {1, 3, 5, 7};
    vector<int> result2 = findAllIndices(arr2, 2);

    cout << "Test Case 2 - Key not present: ";
    if (result2.empty())
        cout << "No indices found";
    else
        for (int index : result2)
            cout << index << " ";
    cout << endl;

    // Test Case 3: Empty array
    vector<int> arr3;
    vector<int> result3 = findAllIndices(arr3, 5);

    cout << "Test Case 3 - Empty array: ";
    if (result3.empty())
        cout << "No indices found";
    cout << endl;

    return 0;
}