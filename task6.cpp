#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Returns the most frequent element in the array
// If multiple modes exist, the smallest mode is returned
int findMode(const vector<int>& arr)
{
    if (arr.empty())
        return -1;

    map<int, int> frequency;

    for (int value : arr)
    {
        frequency[value]++;
    }

    int mode = arr[0];
    int maxFrequency = frequency[mode];

    for (const auto& pair : frequency)
    {
        if (pair.second > maxFrequency)
        {
            maxFrequency = pair.second;
            mode = pair.first;
        }
    }

    return mode;
}