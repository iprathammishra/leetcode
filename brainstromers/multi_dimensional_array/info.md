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

### How to pass 3D array to a functon? 3D arrays are generally called Tensors and are the part of computer graphics and deep learning.

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

int *create1DArray(int N)
{
    int *OneD = new int[N];
    // Filling the values.
    // for (int i = 0; i < N; i++)
    //     matrix[i] = i * 2;

    return OneD;
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

### Creating 2D array within a function.

If you don't want to use vectors and prefer to work with plain arrays to create a multi-dimensional matrix in C++, you can use dynamic arrays. Here's an example of how to create an NxN matrix without using vectors:

```cpp
#include <iostream>

// Function to create an NxN matrix using dynamic arrays
int** createMatrix(int N) {
    int** matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }
    return matrix;
}

// Function to delete the dynamic matrix to free memory
void deleteMatrix(int** matrix, int N) {
    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int N;
    std::cout << "Enter the size of the matrix (N): ";
    std::cin >> N;

    int** myMatrix = createMatrix(N);

    // Example: Setting values in the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            myMatrix[i][j] = i * N + j; // Fill the matrix with some values
        }
    }

    // Display the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << myMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Don't forget to release the allocated memory
    deleteMatrix(myMatrix, N);

    return 0;
}
```

In this code, we create a matrix using dynamic arrays (int\*\*). We allocate memory for the matrix using `new`, set values in the matrix, and later free the allocated memory using the `deleteMatrix` function to prevent memory leaks.

Remember to manage properly when working with dynamic arrays, as shown in the `deleteMatrix` function, to release the memory when you're done using the matrix.

```cpp
int** createMatrix(int N) {
    int** matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }
    return matrix;
}
```

The `int **createMatrix(int N)` function is used to create a two-dimensional (2D) array, which is like a table with rows and columns, in C++. Here's what each part of the code does:

1. `int **createMatrix(int N)`: This line says we're making a function called `createMatrix` that needs a number `N` as input and will give back a special kind of pointer, which we call `int **`. The special pointer is used to manage a 2D array. _For 3D array we use int \*\*\*._
2. `int **matrix = new int*[N]`: Here, we're preparing space for the rows of our 2D array. We're saying, "I want `N` rows." The `matrix` will keep track of these rows.
3. `for (int i = 0; i < N; i++) { matrix[i] = new int[N]; }`: In this part, we're making each row. For each `i` from 0 to `N-1`, we make a new row that has `N` columns. It's like creating a bunch of empty boxes to put our data in.
4. `return matrix;`: Once we've created all the rows and columns, we give back the `matrix`. It's like saying, "Here's your empty 2D array. You can put numbers in it now."

So, this function helps you create a blank 2D array in memory, ready for you to put your data (numbers) into it. It's like creating an empty table that can fill with values later.

### Can matrix ever be 3D?

In standard mathemetical and computer science terminology, a matrix is typically considered a two-demensional (2D) structure. It consists of rows and columns. Eacj element of a matrix is identified by its row and column indices, like `matrix[i][j]`.

A 3D structure is referred to as a "3D array" or a "3D tensor" in mathematics and computer science. These 3D structures extend the concept of a matrix into three dimensions, with elements identified by three indices like `array[i][j][k]`.

So, while matrices are specifically 2D structures, you can certainly work with 3D arrays or tensors in computer programming, but they are conceptually different from matrices. Matrices are often used in linear algebra and various mathematical operations, while 3D arrays are used in applications like computer graphics, scientific simulations, and deep learning for managing and manipulating three-dimensional data.
