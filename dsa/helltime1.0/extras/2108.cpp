class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (const string &word : words)
        {
            string compare = word;
            reverse(compare.begin(), compare.end());
            if (compare == word)
                return word;
        }
        return "";
    }
};