# Deal with Multi-Dimensional Array

### How can I pass a 2D array to a function?

To pass a 2D array to a function in C++, you can use a pointer to a 2D array. Here's an example of how you can modify the `createMatrix` function to take a 2D array of integers as an argument:

```cpp
void createMatrix(int (*matrix)[N], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = i * N + j;
        }
    }
}
```

In this example, `N` is the size of the second dimension of the array, and `n` is the size of the first dimension of the array. The `createMatrix` function takes a pointer to a 2D integer array `matrix` and an integer `n` as arguments. The function initializes the elements of the array using a nested loop.

To call the `createMatrix` function from the `main` function, you can pass a 2D array as an argument:

```cpp
int main()
{
    int matrix[N][N];
    createMatrix(matrix, N);
    // ...
    return 0;
}
```

In this example, `matrix` is a 2D integer array of size `N` by `N`. The `createMatrix` function is called with `matrix` and `N` as arguments.

### What is `int (*matrix)[N]`?

`int (*matrix)[N]` is a pointer to a 2D array of integers WITH `N` columns.

In C++, when you declare a 2D array, the first dimension is optional. This means that you can declare a 2D array with a fixed number of columns, but a variable number of rows. For example, `int matrix[][N]` declares a 2D array of integers with `N` columns, but the number of rows is not specified.

When you pass a 2D array to a function, the array is automatically converted to a pointer to the first element of the array. However, if you want to pass a pointer to a 2D array, you need to specify the size of the second dimension of the array. This is where the syntax `int (*matrix)[N]` comes in.

In this syntax, `(*matrix)` specifies that matrix is a pointer to an array, and `[N]` specifies the size of the second dimension of the array. This allow you to pass a pointer to a 2D array of integers with `N` columns to a function.

### How to pass 3D array to a functon?

To pass a 3D array to a function in C++, you can use a pointer to a 3D array. Here's an example of how you can modify the `createMatrix` function to take a 3D array of integers as an argument:

```cpp
void createMatrix(int (*matrix)[N][M], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                matrix[i][j][k] = i * N * M + j * M + k;
            }
        }
    }
}
```

In this example, `N` and `M` are the sizes of second and third dimensions of the array, respectively, and `n` is the size of the first dimension of the array. The `createMatrix` function takes a pointer to a 3D integer array `matrix` and an integer `n` as arguments. The function initializes the elements of the array using a nested loop.

To call the `createMatrix` function from the `main` function, you can pass a 3D array as an argument:

```cpp
int main()
{
    int matrix[2][N][M];
    createMatrix(matrix, 2);
    // ...
    return 0;
}
```

In this example, `matrix` is a 3D integer array of size `2` by `N` by `M`. The `createMatrix` function is called with `matrix` and `2` as arguments.

### How to pass a 1D array to a function?

To pass a 1D array to a function in C++, you can use a pointer to an array. Here's an example of how you can modify the `printArray` function to take a 1D array of integers as an argument:

```cpp
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
```

In this example, `arr` is a pointer to an integer array, and `n` is the size of this array. The `printArray` function takes `arr` and `n` as arguments and prints the elements of the array using a loop.

To call the `printArray` function from the `main` function, you can pass a 1D array as an argument:

```cpp
int main()
{
    int arr[N] = {1, 2, 3, 4, 5};
    printArray(arr, N);
    // ...
    return 0;
}
```

In this example, `arr` is a 1D integer array of size `N`. The `printArray` function is called with `arr` and `N` as arguments.
