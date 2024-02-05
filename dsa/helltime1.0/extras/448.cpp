class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int val = abs(nums[i]);
            if (1 <= val && val <= nums.size())
                if (nums[val - 1] > 0)
                    nums[val - 1] *= -1;
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
                res.push_back(i + 1);
        return res;
    }
};