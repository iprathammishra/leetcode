class Solution
{
public:
    int minNonZeroProduct(int p)
    {
        using ll = long long;
        const int MOD = 1e9 + 7;
        auto quickPower = [MOD](ll base, ll exponent)
        {
            ll result = 1;
            for (; exponent; exponent >>= 1)
            {
                if (exponent & 1)
                {
                    result = (result * base) % MOD;
                }
                base = (base * base) % MOD;
            }
            return result;
        };
        ll maxValModulo = ((1LL << p) - 1) % MOD;
        ll powerOfPrecedingElements = quickPower(((1LL << p) - 2) % MOD, (1LL << (p - 1)) - 1);
        return maxValModulo * powerOfPrecedingElements % MOD;
    }
};