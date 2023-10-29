# Rotating a matrix.

The code implementation below is done using `vectors` but we can also perform it using `Dynamic Arrays`.

```cpp
void rotateMatrix(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();

    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer;
        int last = n - 1 - layer;

        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top = matrix[first][i];  // Save top element

            // Left -> Top
            matrix[first][i] = matrix[last - offset][first];

            // Bottom -> Left
            matrix[last - offset][first] = matrix[last][last - offset];

            // Right -> Bottom
            matrix[last][last - offset] = matrix[i][last];

            // Top -> Right
            matrix[i][last] = top;  // Restore top element
        }
    }
}
```

This is how you rotate a matrix by 90 degrees.
<br>

Before moving on we need to understand what `layers`, and `top`, `bottom`, `left`, `right` means. Let's take an
example of a 4x4 matrix below to understand the `layers` concept.

```txt
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
```

In this matrix we have 2 layers. Layers 1: `{1, 5, 9, 13, 14, 15, 16, 12, 8, 4, 3, 2}` and Layer 2: `{6, 10, 11, 7}`.
<br>

Now, lets understand the concept of `top, bottom, left, right` with a 3x3 matrix.

```txt
1 2 3
4 5 6
7 8 9
```

- `Top`: 1
- `Bottom`: 9
- `Left`: 7
- `Right`: 3

Now, lets break down the `rotateMatrix` function step-by-step with an example. We will use a 3x3 matrix to illustrate the rotation. We'll start with the original matrix.

```txt
1 2 3
4 5 6
7 8 9
```

Now, let's walk through the code:

1. We calculate the size of the matrix `n`, which is 3 in this case (since it's a 3x3 matrix).
2. We iterate through each layer of the matrix, starting from the outermost layer (layer 0) and moving inwards. In this example, there's only one layer (layer 0) becaues it's a 3x3 matrix, but the code can handle larger matrices with more layers.
3. Within each layer, we have a loop that iterates through the elements in that layer. For example, in layer 0, we iterate through elements `1`, `2`, and `3`.
4. For each element within the layer, we calculate an `offset` to help us with the rotation. We save the value of the top element in the variable `top`.
5. Then, we perform a cyclic rotation of four elements (left, bottom, right, top) to rotate the values within the layer.

- `Left -> Top`: We replace the top element with the value from the left element.
- `Bottom -> Left`: We replace the left element with the value from the bottom element.
- `Right -> Bottom`: We replace the bottom element with the value from the right element.
- `Top -> Right`: We replace the right element with the value saved in the `top` variable.

6. This process continues for all elements in the current layer, effectively rotating the values within that layer by 90 degrees.

Rotated Matrix:

```txt
7 4 1
8 5 2
9 6 3
```

So, the code has effectively rotated the original matrix by 90-degrees in place, as you can see in the resulting rotated matrix.
