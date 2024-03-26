class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int ones = 0;
        int zeros = 0;
        int maxSum = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] == 1 ? ones++ : zeros++;
            int diff = ones - zeros;
            if (m.count(diff))
            {
                maxSum = max(maxSum, i - m[diff]);
            }
            else
            {
                m[diff] = i;
            }
        }
        return maxSum;
    }
};