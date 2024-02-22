class Solution
{
public:
    int monkeyMove(int numSteps)
    {
        const int MODULO = 1e9 + 7;
        using Long = long long;

        auto quickPower = [&](Long base, int exponent)
        {
            Long result = 1;
            while (exponent > 0)
            {
                if (exponent & 1)
                {
                    result = (result * base) % MODULO;
                }
                base = (base * base) % MODULO;
                exponent >>= 1;
            }
            return result;
        };

        return (quickPower(2, numSteps) - 2 + MODULO) % MODULO;
    }
};