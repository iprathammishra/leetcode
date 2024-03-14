class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> count;
        count[0] = 1;
        int curr_sum = 0;
        int ans = 0;
        for (int num : nums)
        {
            curr_sum += num;
            if (count.find(curr_sum - goal) != count.end())
            {
                ans += count[curr_sum - goal];
            }
            count[curr_sum]++;
        }
        return ans;
    }
};