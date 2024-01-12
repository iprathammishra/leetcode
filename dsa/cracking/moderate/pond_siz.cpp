// 19. **Pond Sizes:** You have an integer matrix representing a plot of land, where the value at that location represents the height above sea level. A value of zero indicates water. A pond is a region of water connected vertically, horizontally, or diagonally. The size of the pond is the total number of connected water cells. Write a method to compute the sizes of all ponds in the matrix.

// Example:
// Input:

// 0 2 1 0
// 0 1 0 1
// 1 1 0 1
// 0 1 0 1

// Output: 2, 3, 1 (in any order)
#include <iostream>
#include <vector>
void dfs(std::vector<std::vector<int>> &matrix, int row, int col, int &size)
{
    if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size() || matrix[row][col] != 0)
        return;
    matrix[row][col] = -1;
    size++;
    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
            dfs(matrix, row + i, col + j, size);
}
std::vector<int> pondSizes(std::vector<std::vector<int>> &matrix)
{
    std::vector<int> result;
    for (int i = 0; i < matrix.size(); ++i)
        for (int j = 0; j < matrix[0].size(); ++j)
            if (matrix[i][j] == 0)
            {
                int size = 0;
                dfs(matrix, i, j, size);
                result.push_back(size);
            }
    return result;
}
int main()
{
    std::vector<std::vector<int>> land = {
        {0, 2, 1},
        {0, 1, 0},
        {1, 1, 0},
        {0, 1, 0}};
    std::vector<int> pondSizesResult = pondSizes(land);

    std::cout << "Pond Sizes: ";
    for (int size : pondSizesResult)
    {
        std::cout << size << " ";
    }
    std::cout << std::endl;

    return 0;
}

// https://chat.openai.com/share/7f3327f5-84f7-42fd-bf9c-a11d3718bf7e