class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int resultSign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long long absDividend = abs(static_cast<long long>(dividend));
        long long absDivisor = abs(static_cast<long long>(divisor));
        long long result = 0;
        while (absDividend >= absDivisor)
        {
            int shiftCount = 0;
            while (absDividend >= (absDivisor << (shiftCount + 1)))
            {
                ++shiftCount;
            }
            result += 1ll << shiftCount;
            absDividend -= absDivisor << shiftCount;
        }
        result *= resultSign;
        if (result >= INT32_MIN && result <= INT32_MAX)
        {
            return static_cast<int>(result);
        }
        return INT32_MAX;
    }
};