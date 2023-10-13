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
    if (text.length() == 0)
        return 0;
    vector<char> onlyRep;
    vector<char> data;
    int counter = 2;
    int mainN;
    for (int i = 0; i < text.length(); i++)
    {
        data.push_back(text[i]);
    }
    onlyRep = data;
    for (int i = 0; i <= onlyRep.size() + 1; i++)
    {
        for (int j = i + 1; j <= onlyRep.size() + 1; j++)
        {
            if (onlyRep[i] == onlyRep[j])
            {
                onlyRep.erase(onlyRep.begin() + i);
            }
        }
    }
    if (onlyRep.size() == 1)
        return 1;
    vector<char> compare;
    int length = data.size();
    int carry = 0;
    while (counter <= length)
    {
        for (int n = 0; n < length; n++)
        {
            for (int m = n; m < counter + carry; m++)
            {
                if (m == length || (counter + carry) > length)
                    break;
                else
                    compare.push_back(data[m]);
            }
            bool flag = false;
            bool fi = false;
            for (int i = 0; i < compare.size(); i++)
            {
                for (int j = i + 1; j < compare.size(); j++)
                {
                    if (compare[i] == compare[j])
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag == true)
                {
                    fi = true;
                    break;
                }
            }
            if (fi == false)
            {
                for (char element : compare)
                {
                    mainN = compare.size();
                }
            }
            compare = {};
            carry++;
            if (flag == false)
                break;
        }
        counter++;
        carry = 0;
    }
    return mainN;
}

int main()
{
    cout << longestSubstring("abcabc*& 6typpppppe");
    return 0;
}