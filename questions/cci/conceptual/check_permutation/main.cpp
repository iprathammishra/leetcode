// **Check Permutation:** Given two strings, write a method to decide if one is a permutation of the other.
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
bool arePermutations(const string &t1, const string &t2)
{
    if (t1.length() != t2.length())
        return false;
    unordered_map<char, int> charCount;
    for (char c : t1)
        charCount[c]++;
    for (char c : t2)
    {
        if (charCount.find(c) == charCount.end() || charCount[c] <= 0) // The first condition checks is c is present in the charCount or not and the second condition checks if charCount[c]'s value is negative or equal to 0.
            return false;
        charCount[c]--;
    }
    for (const auto &pair : charCount)
        if (pair.second != 0)
            return false;
    return true;
}
int main()
{
    string text1 = "Pratham";
    string text2 = "raPhtam";
    cout << arePermutations(text1, text2);
    return 0;
}