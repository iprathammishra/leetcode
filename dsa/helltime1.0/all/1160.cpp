class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int charCount[26] = {0};
        for (char c : chars)
        {
            charCount[c - 'a']++;
        }
        int totalLength = 0;
        for (string word : words)
        {
            int wordCount[26] = {0};
            bool wordFormed = true;
            for (char index : word)
            {
                if (++wordCount[index - 'a'] > charCount[index - 'a'])
                {
                    wordFormed = false;
                    break;
                }
            }
            if (wordFormed)
            {
                totalLength += word.size();
            }
        }
        return totalLength;
    }
};