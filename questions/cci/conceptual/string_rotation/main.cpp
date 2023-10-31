// **String Rotation:** Assume you have method isSubstring which checks if one word is a substring of another. Given two strings, S1 and S2, write a code to check if S2 is a rotation of S1 using only one call to isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat").
#include <iostream>
#include <string>
using namespace std;
bool isRotationSubstring(const string &str1, const string &str2)
{
    return (str1.length() != str2.length()) ? false : ((str1 + str1).find(str2) != string::npos);
}
int main()
{
    cout << isRotationSubstring("waterbottle", "terbottlewa");
    return 0;
}