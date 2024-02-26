class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        int lower = 0;
        int upper = 0;
        for (const int &num : nums)
        {
            lower = max(lower, num);
            upper += num;
        }
        function<bool(int)> can_split = [&](int capacity) -> bool
        {
            int current_sum = 0;
            int k_count = 1;
            for (const int &num : nums)
            {
                current_sum += num;
                if (current_sum > capacity)
                {
                    current_sum = num;
                    k_count++;
                }
            }
            return k_count <= k;
        };
        while (lower < upper)
        {
            int mid = (lower + upper) / 2;
            if (can_split(mid))
            {
                upper = mid;
            }
            else
            {
                lower = mid + 1;
            }
        }
        return lower;
    }
};