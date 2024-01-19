// 16. **The Masseuse:** A popular masseuse receives a sequence of back-to-back appointments and therefore she cannot accept any adjacent requests. Given a sequence of back-to-back appointment requests (all multiples of 15 minutes, none overlap, and none can be moved), find the optimal (highest total booked minutes) set the masseuse can honor. Return the number of minutes.

// Example:
// Input: {30, 15, 60, 75, 45, 15, 15, 45}
// Output: 180 minutes ({30, 60, 45, 45}).
#include <iostream>
#include <vector>
int masseuse(const std::vector<int> &inp)
{
    int n = inp.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return inp[0];

    std::vector<int> dp(n, 0);
    dp[0] = inp[0];
    dp[1] = std::max(inp[0], inp[1]);

    for (int i = 2; i < n; ++i)
        dp[i] = std::max(dp[i - 1], dp[i - 2] + inp[i]);
    return dp[n - 1];
}
int main()
{
    std::vector<int> inp = {30, 15, 60, 75, 45, 15, 15, 45};
    std::cout << masseuse(inp);
    return 0;
}

// https://chat.openai.com/share/dbc505bc-1a9a-4551-8841-747145f2d695