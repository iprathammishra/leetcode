// **Zero Matrix:** Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.
#include <iostream>
#include <set>
using namespace std;
int **createMatrix(int m, int n)
{
    int **matrix = new int *[m];
    for (int i = 0; i < m; i++)
        matrix[i] = new int[n];
    return matrix;
}
void displayMatrix(int **matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
void zeroMatrix(int **matrix, int M, int N)
{
    set<int> rows, cols;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (matrix[i][j] == 0)
            {
                rows.insert(i);
                cols.insert(j);
            }
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (rows.count(i) || cols.count(j))
                matrix[i][j] = 0;
}
int main()
{
    int M = 4;
    int N = 3;
    int **myMatrix = createMatrix(M, N);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            myMatrix[i][j] = i + j - 1;
    displayMatrix(myMatrix, M, N);
    cout << endl;
    zeroMatrix(myMatrix, M, N);
    displayMatrix(myMatrix, M, N);
    return 0;
}