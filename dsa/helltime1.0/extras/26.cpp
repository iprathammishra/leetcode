class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        unordered_set<int> sset(nums.begin(), nums.end());
        vector<int> vec(sset.begin(), sset.end());
        sort(vec.begin(), vec.end());
        for (int i = 0; i < sset.size(); i++)
            nums[i] = vec[i];
        return sset.size();
    }
};