class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int val = abs(nums[i]);
            if (nums[val - 1] > 0)
                nums[val - 1] *= -1;
            else if (nums[val - 1] < 0)
                res.push_back(val);
        }
        return res;
    }
};