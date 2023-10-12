/*
Description:
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/
#include <iostream>
#include <vector>
using namespace std;
int longestSubstring(string text)
{
    vector<char> data;
    vector<string> result;
    for (int i = 0; i < text.length(); i++)
    {
        data.push_back(text[i]);
    }
    // Traverse in data in such a way that you only consider the char(s) only once. For example for int 1: (p) is complete move to int 2: (pw) is complete move to int 3: (pww) is not complete so move to (wwk) which is also not complete so move to (wke) which is complete so move to int 4: like that.
    cout << endl;
    return 0;
}
int main()
{
    cout << longestSubstring("pwwkew");
    return 0;
}