# Frequency Approach to look for Palindrome String. (`Permutation Example.`)

To check if a given string is a permutation of a palindrome, we can use a simple algorithm. A palindrome is a string that reads the same forwards and backwards. For a string to be a permutation of a palindrome, it means that its characters can be rearranges in such a way that it forms a valid palindrome.

```cpp
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
```

The algorithm to solve this problem is as follows:

1. Count the frequency of each character in the string.
2. Ensure that at most one character has an odd frequency, while all other characters have even frequencies.
3. If this condition is met, the string can be rearranged into a palindrome; otherwise it cannot.

In this code, we count the frequency of characters, ignoring non-alphabetic characters. We then check if there is at most one character with an odd frequency. If this condition is met, the string is a permutation of a palindrome.
