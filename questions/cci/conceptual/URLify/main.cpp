// **URLify:** Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.

// Example:
// Input: "Mr John Smith "
// Output: "Mr%20John%20Smith"
#include <iostream>
#include <string>
using namespace std;
string URLify(const string &input)
{
    string result;
    for (char c : input)
        if (static_cast<int>(c) == 32)
            result = result + "%20";
        else
            result = result + c;
    return result;
}
int main()
{
    string input = "Mr John Smith ";
    input.erase(input.find_last_of(' '));
    cout << URLify(input);
    return 0;
}