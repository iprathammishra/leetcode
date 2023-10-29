#include <iostream>
using namespace std;
int **createMatrix(int n)
{
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];
    return matrix;
}

void deleteMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}
void rotateMatrixBy90Degree(int **matrix, int n)
{
    for (int layer = 0; layer < n / 2; layer++)
    {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; i++)
        {
            int offset = i - first;
            int top = matrix[first][i]; // SAVE TOP ELEMENT
            // LEFT -> TOP
            matrix[first][i] = matrix[last - offset][last];
            // BOTTOM -> LEFT
            matrix[last - offset][last] = matrix[last][last - offset];
            // RIGHT -> BOTTOM
            matrix[last][last - offset] = matrix[i][last];
            // TOP -> RIGHT
            matrix[i][last] = top;
        }
    }
}
void displayMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int N = 3;
    int **MyMatrix = createMatrix(N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            MyMatrix[i][j] = i * N + j;
    displayMatrix(MyMatrix, N);
    cout << "After 90 Degree Rotation." << endl;
    rotateMatrixBy90Degree(MyMatrix, N);
    displayMatrix(MyMatrix, N);
    deleteMatrix(MyMatrix, N);
    return 0;
}