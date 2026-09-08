#include <iostream>
#include <string>
using namespace std;

int naivePatternMatching(const string& text, const string& pattern);

int main()
{
    // Test Case 1: Pattern at the beginning
    cout << "Test Case 1: "
         << naivePatternMatching("Hello World", "Hello") << endl;

    // Test Case 2: Pattern at the end
    cout << "Test Case 2: "
         << naivePatternMatching("Hello World", "World") << endl;

    // Test Case 3: Pattern not present
    cout << "Test Case 3: "
         << naivePatternMatching("Hello World", "Python") << endl;

    // Test Case 4: Empty pattern
    cout << "Test Case 4: "
         << naivePatternMatching("Hello World", "") << endl;

    return 0;
}