class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> hashmap;
        int zeros = 0;
        int ones = 0;
        int maxSum = 0;
        hashmap[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] == 1 ? ones++ : zeros++;
            int diff = ones - zeros;
            if (hashmap.count(diff))
            {
                maxSum = max(maxSum, i - hashmap[diff]);
            }
            else
            {
                hashmap[diff] = i;
            }
        }
        return maxSum;
    }
};