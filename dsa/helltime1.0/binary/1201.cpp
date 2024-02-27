class Solution
{
public:
    long long lcm(long long a, long long b)
    {
        return a / gcd(a, b) * b;
    }
    long long gcd(long long a, long long b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int nthUglyNumber(int n, int a, int b, int c)
    {
        long long lcmAB = lcm(a, b);
        long long lcmBC = lcm(b, c);
        long long lcmAC = lcm(a, c);
        long long lcmABC = lcm(lcmAB, c);

        long long left = 1, right = 2000000000;
        while (left < right)
        {
            long long mid = (left + right) / 2;
            long long count = mid / a + mid / b + mid / c - mid / lcmAB - mid / lcmBC - mid / lcmAC + mid / lcmABC;
            if (count >= n)
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