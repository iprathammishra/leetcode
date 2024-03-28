class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        map<int, int> m;
        int total = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            m[nums[right]]++;
            while (m[nums[right]] > k)
            {
                m[nums[left]]--;
                left++;
            }
            total = max(total, right - left + 1);
        }
        return total;
    }
};