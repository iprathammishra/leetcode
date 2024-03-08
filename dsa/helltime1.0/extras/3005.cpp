class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> map;
        int maxn = 0;
        for (auto it : nums)
        {
            map[it]++;
            maxn = max(maxn, map[it]);
        }
        int count = 0;
        for (auto it : nums)
        {
            if (map[it] == maxn)
            {
                count++;
            }
        }
        return count;
    }
};