class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> left_side(nums.begin(), nums.begin() + n);
        vector<int> right_side(nums.begin() + n, nums.end());
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back(left_side[i]);
            res.push_back(right_side[i]);
        }
        return res;
    }
};