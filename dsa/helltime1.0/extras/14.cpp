class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int numString = strs.size();
        for (int i = 0; i < strs[0].size(); i++)
        {
            for (int j = 1; j < numString; j++)
            {
                if (strs[j][i] != strs[0][i])
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs.front();
    }
};