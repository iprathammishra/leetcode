class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        int validNumber = sqrt(n);
        dp[0] = 0;
        for (int i = 1; i <= validNumber; i++)
        {
            int square = i * i;
            for (int j = square; j <= n; j++)
                dp[j] = min(dp[j], dp[j - square] + 1);
        }
        return dp[n];
    }
};