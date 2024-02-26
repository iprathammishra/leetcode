class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if ((long long)m * k > bloomDay.size())
        {
            return -1;
        }
        int lower = *min_element(bloomDay.begin(), bloomDay.end());
        int upper = *max_element(bloomDay.begin(), bloomDay.end());
        function<bool(int)> can_make = [&](int capacity) -> bool
        {
            int flowers = 0;
            int bouquets = 0;
            for (const int &bloom : bloomDay)
            {
                flowers = (bloom <= capacity) ? (flowers + 1) : 0;
                if (flowers == k)
                {
                    flowers = 0;
                    bouquets++;
                }
            }
            return bouquets >= m;
        };
        while (lower < upper)
        {
            int mid = (lower + (upper - lower) / 2);
            if (can_make(mid))
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