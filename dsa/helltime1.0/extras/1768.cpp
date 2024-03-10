class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        string res = "";
        for (int i = 0; i < n && i < m; i++)
        {
            res += word1[i];
            res += word2[i];
        }
        if (n > m)
        {
            res += word1.substr(m);
        }
        else if (n < m)
        {
            res += word2.substr(n);
        }
        return res;
    }
};