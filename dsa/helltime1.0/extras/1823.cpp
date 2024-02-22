class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        if (n == 1)
        {
            return 1;
        }
        int winner = findTheWinner(n - 1, k);
        int adjusted_winner = (winner + k) % n;
        return adjusted_winner == 0 ? n : adjusted_winner;
    }
};