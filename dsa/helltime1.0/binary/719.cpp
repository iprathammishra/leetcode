class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back() - nums.front();
        function<int(vector<int>, int)> count_pairs = [&](const vector<int> &numbers, int dist) -> int
        {
            int count = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                int target = nums[i] - dist;
                int j = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
                count += i - j;
            }
            return count;
        };
        while (left < right)
        {
            int mid = (left + right) >> 1;
            if (count_pairs(nums, mid) >= k)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};