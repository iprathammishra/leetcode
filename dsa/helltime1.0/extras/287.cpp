class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        map<int, int> map;
        for (const auto it : nums)
        {
            map[it]++;
        }
        for (const auto [i, j] : map)
        {
            if (j >= 2)
            {
                return i;
            }
        }
        return -1;
    }
};