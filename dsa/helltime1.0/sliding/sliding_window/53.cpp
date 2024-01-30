class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int current_sum = nums[0];
        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            current_sum = std::max(nums[i], current_sum + nums[i]);
            max_sum = std::max(max_sum, current_sum);
        }
        return max_sum;
    }
};

// Kadane's Algorithm