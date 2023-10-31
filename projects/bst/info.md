# `Project: Binary Search Tree (BST) Operations`

## Description:

Create a C++ program that allows users to interact with a binary search tree. You can implement basic BST operations and practive iterative tree traversal with the following functionalities:

1. `Insertion:` Allow the user to insert element into the BST iteratively.
2. `Search:` Implement an iterative search function to find whether an element exists in the BST.
3. `Deletion:` Allow the user to delete elements from the BST.
4. `Iterative Traversal:`

- Implement iterative versions of in-order, pre-order, and post-order tree traversals.
- Allow the user to choose a traversal type and display the result.

A `Binary Search Tree (BST)` is a collection of nodes arranged in a way where they maintain BST properties.

- Every node in the `left subtree` has a value `less` than the value of its parent node.
- Every node in the `right subtree` has a value `greater than or equal to` the vLue of its parent node.

## User Interface:

You can create a simple command-line interface where users can input commands to perform these operations. For example:

```txt
Binary Search Tree Operations:
1. Insert an element
2. Search for an element
3. Delete an element
4. Perform iterative in-order traversal
5. Perform iterative pre-order traversal
6. Perform iterative post-order traversal
7. Exit

Enter your choice:
```

## Implementation:

You can define a `Node` structure to represent the nodes of the binary search tree and implement the iterative operations accordingly. Here's a simplified code structure for your project.

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinarySearchTree {
public:
    // Constructor, destructor, and other member functions for BST operations

    // Iterative traversal functions (in-order, pre-order, and post-order)

    // Other helper functions as needed
};

int main() {
    // Initialize the BST

    int choice;
    while (true) {
        // Display the menu and get user's choice

        switch (choice) {
            case 1:
                // Insert an element
                break;
            case 2:
                // Search for an element
                break;
            case 3:
                // Delete an element
                break;
            case 4:
                // Perform iterative in-order traversal
                break;
            case 5:
                // Perform iterative pre-order traversal
                break;
            case 6:
                // Perform iterative post-order traversal
                break;
            case 7:
                // Exit the program
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
```
