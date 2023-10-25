// **Is Unique:** Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
#include <iostream>
#include <string>
using namespace std;
bool isUnique(string &text)
{
    if (text.length() > 128)
        return false; // There are more characters than ASCII characters.
    bool charSet[128] = {0};
    for (char c : text)
    {
        int index = static_cast<int>(c); // Casting the character c into int.
        if (charSet[index])              // If we find a position that is already true then return false.
            return false;
        charSet[index] = true;
    }
    return true;
}
int main()
{
    string text = "Prathm";
    cout << isUnique(text);
    return 0;
}

// If additional data structures are not allowed than we can implement this with O(n^2) using nested loops and comparing values.