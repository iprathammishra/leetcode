class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int min_cap = 0;
        int max_cap = 0;
        for (const int &weight : weights)
        {
            min_cap = max(min_cap, weight);
            max_cap += weight;
        }
        function<bool(int)> can_ship = [&](int capacity) -> bool
        {
            int current_weight = 0;
            int day_count = 1;
            for (const int &weight : weights)
            {
                current_weight += weight;
                if (current_weight > capacity)
                {
                    current_weight = weight;
                    day_count++;
                }
            }
            return day_count <= days;
        };
        while (min_cap < max_cap)
        {
            int mid_cap = (min_cap + max_cap) / 2;
            if (can_ship(mid_cap))
            {
                max_cap = mid_cap;
            }
            else
            {
                min_cap = mid_cap + 1;
            }
        }
        return min_cap;
    }
};