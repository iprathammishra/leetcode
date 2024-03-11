class Solution
{
public:
    string customSortString(string order, string s)
    {
        int charCount[26] = {0};
        for (auto it : s)
        {
            charCount[it - 'a']++;
        }
        string sortedStr;
        for (auto it : order)
        {
            while (charCount[it - 'a']-- > 0)
            {
                sortedStr += it;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (charCount[i] > 0)
            {
                sortedStr += string(charCount[i], i + 'a');
            }
        }
        return sortedStr;
    }
};