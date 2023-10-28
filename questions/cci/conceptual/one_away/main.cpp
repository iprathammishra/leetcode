// **One Away:** There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

// Example:
// pale, ple -> true
// pales, pale -> true
// pale, bale -> true
// pale, bake -> false
#include <iostream>
#include <string>
using namespace std;
bool isOneAway(const string &str1, const string &str2)
{
    if (abs(static_cast<int>(str1.length() - str2.length()) > 1))
        return false;
    const string &shorter = (str1.length() > str2.length()) ? str2 : str1;
    const string &longer = (str1.length() > str2.length()) ? str1 : str2;
    int index1 = 0;
    int index2 = 0;
    bool counterBool = false;
    while (index1 < shorter.length() && index2 < longer.length())
    {
        if (shorter[index1] != longer[index2])
        {
            if (counterBool)
                return false;
            counterBool = true;
            if (shorter.length() == longer.length() && counterBool)
                index1++;
        }
        else
            index1++;
        index2++;
    }
    return true;
}
int main()
{
    cout << isOneAway("pales", "pale") << " (Expected: true)\n";
    cout << isOneAway("pale", "ple") << " (Expected: true)\n";
    cout << isOneAway("pale", "bale") << " (Expected: true)\n";
    cout << isOneAway("pale", "bake") << " (Expected: false)\n";
    cout << isOneAway("bal", "pal") << " (Expected: true)\n";
    return 0;
}