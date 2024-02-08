class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 3)
        {
            vector<int> vec = {nums[i], nums[i + 1], nums[i + 2]};
            if (vec[2] - vec[0] > k)
                return {};
            res.push_back(vec);
        }
        return res;
    }
};