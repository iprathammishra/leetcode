class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (const int &num : nums)
            map[num]++;
        for (const auto &[i, j] : map)
            if (j != 1)
                return true;
        return false;
    }
};