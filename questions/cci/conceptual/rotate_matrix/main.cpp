// **Rotate Matrix : **Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees.Can you do this in place ?
// For Example:
// We have a matrix as below:
// 1 2 3
// 4 5 6
// 7 8 9
// If we rotate this matrix by 90 degrees the resulted matrix will be:
// 7 4 1
// 8 5 2
// 9 6 3
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

void displayMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
void rotateMatrixBy90Degree(int **matrix, int n)
{
    int **tempMatrix = createMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tempMatrix[i][j] = matrix[i][j];
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j >= 0; j--)
            matrix[i][n - j - 1] = tempMatrix[j][i];
    deleteMatrix(tempMatrix, n);
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