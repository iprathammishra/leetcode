class Solution
{
public:
    int mySqrt(int x)
    {
        long long left = 0;
        int right = x;
        long long mid;
        while (left < right)
        {
            mid = left + ((right - left + 1) >> 1);
            if (mid * mid <= x)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return static_cast<int>(left);
    }
};