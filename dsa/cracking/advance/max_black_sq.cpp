// 23. **Max Black Square:** Imagine you have a square matrix, where each cell (pixel) is either black or white. Design an alogrithm to find the maximum subsquare such that all four borders are filled with black pixels.

#include <iostream>
#include <vector>

using namespace std;

int findMaxBlackSquare(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    if (n == 0)
        return 0;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = matrix[i][0];
        dp[0][i] = matrix[0][i];
    }

    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            if (matrix[i][j] == 1)
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;

    int maxBlackSquareSize = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            maxBlackSquareSize = max(maxBlackSquareSize, dp[i][j]);

    return maxBlackSquareSize;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0},
        {1, 1, 0, 1, 1}};

    int result = findMaxBlackSquare(matrix);

    cout << "Maximum black square size: " << result << endl;

    return 0;
}

// https://chat.openai.com/share/480355bf-a035-4917-8b9a-175d350c89e8