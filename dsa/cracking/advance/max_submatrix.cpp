// 24. **Max Submatrix:** Given an NxN matrix of positive and negative integers, write code to find the submatrix with the largest possible sum.

// Kadane's algorithm

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubarraySum(const vector<int> &arr, int &start, int &end)
{
    int maxSum = INT_MIN;
    int currentSum = 0;
    int currentStart = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
        currentSum += arr[i];

        if (currentSum < 0)
        {
            currentSum = 0;
            currentStart = i + 1;
        }

        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            start = currentStart;
            end = i;
        }
    }

    return maxSum;
}

int maxSubmatrixSum(const vector<vector<int>> &matrix, int &startRow, int &endRow, int &startCol, int &endCol)
{
    int maxSum = INT_MIN;
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    for (int left = 0; left < numCols; ++left)
    {
        vector<int> temp(numRows, 0);

        for (int right = left; right < numCols; ++right)
        {
            for (int i = 0; i < numRows; ++i)
            {
                temp[i] += matrix[i][right];
            }

            int currentSum = 0;
            int tempStartRow = 0;
            int tempEndRow = 0;

            int tempMaxSum = maxSubarraySum(temp, tempStartRow, tempEndRow);

            if (tempMaxSum > maxSum)
            {
                maxSum = tempMaxSum;
                startRow = tempStartRow;
                endRow = tempEndRow;
                startCol = left;
                endCol = right;
            }
        }
    }

    return maxSum;
}

int main()
{
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 10, 1, 3},
        {-4, -1, 1, 7, -6}};

    int startRow, endRow, startCol, endCol;
    int result = maxSubmatrixSum(matrix, startRow, endRow, startCol, endCol);

    cout << "Maximum Submatrix Sum: " << result << endl;
    cout << "Submatrix coordinates: (" << startRow << ", " << startCol << ") to (" << endRow << ", " << endCol << ")" << endl;

    return 0;
}
