class Solution
{
public:
    int findKthNumber(int m, int n, int k)
    {
        int lower = 1;
        int upper = m * n;
        int count = 0;
        while (lower < upper)
        {
            int count = 0;
            int mid = lower + (upper - lower) / 2;
            for (int i = 1; i <= m; i++)
            {
                count += min(mid / i, n);
            }
            if (count >= k)
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