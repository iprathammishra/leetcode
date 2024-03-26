class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int lastindex[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            lastindex[s[i] - 'a'] = i;
        }
        int maxcount = 0;
        int anchor = 0;
        vector<int> partitions;
        for (int i = 0; i < s.length(); i++)
        {
            maxcount = max(maxcount, lastindex[s[i] - 'a']);
            if (maxcount == i)
            {
                partitions.emplace_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return partitions;
    }
};