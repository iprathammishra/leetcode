class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<long long> sum_nums = {0};
        for (const int &num : nums)
        {
            long long n = sum_nums.back() + num;
            sum_nums.push_back(n);
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] >= sum_nums[i])
            {
                continue;
            }
            return sum_nums[i + 1];
        }
        return -1;
    }
};