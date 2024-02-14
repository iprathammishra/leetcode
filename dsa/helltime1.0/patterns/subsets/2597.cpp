class Solution
{
public:
    int beautifulSubsets(vector<int> &nums, int k)
    {
        int countSubsets = -1;
        int countNums[1010]{};
        function<void(int)> dfs = [&](int index) -> void
        {
            if (index >= nums.size())
            {
                countSubsets++;
                return;
            }
            dfs(index + 1);
            bool isBeautifulIncreament = nums[index] + k >= 1010 || countNums[nums[index] + k] == 0;
            bool isBeautifulDecreament = nums[index] - k < 0 || countNums[nums[index] - k] == 0;
            if (isBeautifulIncreament && isBeautifulDecreament)
            {
                countNums[nums[index]]++;
                dfs(index + 1);
                countNums[nums[index]]--;
            }
        };
        dfs(0);
        return countSubsets;
    }
};