class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int current = 1;
        int result = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] < nums[i])
            {
                current++;
            }
            else
            {
                current = 1;
            }
            result = max(result, current);
        }
        return result;
    }
};