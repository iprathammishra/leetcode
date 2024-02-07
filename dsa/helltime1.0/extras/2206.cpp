class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        unordered_map<int, int> fmap;
        for (const int &i : nums)
            fmap[i]++;
        for (const auto &[i, j] : fmap)
            if (j % 2 != 0)
                return false;
        return true;
    }
};