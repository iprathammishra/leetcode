class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> fmap;
        for (const int &i : nums)
            fmap[i]++;
        sort(nums.begin(), nums.end(), [&](int a, int b)
             { return fmap[a] == fmap[b] ? a > b : fmap[a] < fmap[b]; });
        return nums;
    }
};