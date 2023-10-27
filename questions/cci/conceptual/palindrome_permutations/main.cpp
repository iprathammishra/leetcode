// **Palindrome Permutation:** Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same in forwards and backwards. A permutation is a rearrangement of letter. The palindrome does not need to be limited to just dictonary words.

// Example:
// Input: Tact Coa
// Output: True (permutations: "taco cat", "atco cta", etc.)
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
bool checkPalindromePermutation(const string &str)
{
    unordered_map<char, int> charFrequency;
    bool oddCharFound = false;
    for (char c : str)
        if (isalpha(c))
            charFrequency[tolower(c)]++;
    for (const auto &pair : charFrequency)
    {
        if (pair.second % 2 == 1)
        {
            if (oddCharFound)
                return false;
            oddCharFound = true;
        }
    }
    return true;
}
int main()
{
    cout << checkPalindromePermutation("Tact Coa");
    return 0;
}