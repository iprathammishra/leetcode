class Solution
{
public:
    int maxNiceDivisors(int primeFactors)
    {
        if (primeFactors < 4)
        {
            return primeFactors;
        }
        const int MOD = 1e9 + 7;
        auto quickPower = [&](long long base, long long exponent) -> int
        {
            long long result = 1;
            while (exponent > 0)
            {
                if (exponent & 1)
                {
                    result = (result * base) % MOD;
                }
                base = (base * base) % MOD;
                exponent >>= 1;
            }
            return static_cast<int>(result);
        };
        if (primeFactors % 3 == 0)
        {
            return quickPower(3, primeFactors / 3);
        }
        if (primeFactors % 3 == 1)
        {
            return static_cast<int>((quickPower(3, primeFactors / 3 - 1) * 4L) % MOD);
        }
        return static_cast<int>((quickPower(3, primeFactors / 3) * 2) % MOD);
    }
};