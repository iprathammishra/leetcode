# 14 Patterns to Solve Any Interview Question

### Sliding Window

Ways to identify that the given problem might require a sliding window:

- The problem input is a linear data structure such as a linked list, array, or string
- You're asked to find the longest/shortest substring, subarray, or a desired value.

Problems:

- Maximum sum subarray of size 'K' (easy)
- Longest substring with 'K' distinct characters (medium)
- String anagrams (hard)

### Two Pointers or Iterators

Ways to identify when to use the Two Pointer method:

- It will feature problems where you deal with sorted arrays (or linked lists) and need to find a set of elements that fulfill certain constraints.
- The set of elements in the array is a pair, a triplet, or even a subarray.

Problems:

- Squaring a sorted array (easy)
- Triplets that sum to zero (medium)
- Comparing strings that contain backspaces (medium)

### Fast and Slow Pointers

Algorithms:

- Hare & Tortoise Algorithm

How do you identify when to use the Fast and Slow pattern?

- The problem will deal with a loop in a linked list or array.
- When you need to know the position of a certain element or the overall length of the linked list.

When should I use it over the Two Pointer method mentioned above?

- There are some cases where you shouldn't use the Two Pointer approach such as in a singly linked list where you can't move in a backward direction. An example of when to use the Fast and Slow pattern is when you're trying to determine if a linked list is a palindrome.

Problems:

- Linked List Cycle (easy)
- Palindrome Linked List (medium)
- Cycle in a Circular Array (hard)

### Merge Intervals

How do you identify when to use the Merge Intervals pattern?

- If you're asked to produce a list with only mutually exclusive intervals.
- If you hear the term "overlapping intervals".

Problems:

- Intervals Intersection (medium)
- Maximum COU Load (hard)

### Cyclic Sort

How do I Identify this pattern?

- There will be problems involving sorted array with numbers in a given range.
- If the problem asks you to find the missing/duplicate/smallest number in an sorted/rotated array.

Problems:

- Find the Missing Number (easy)
- Find the Smallest Missing Positive Number (medium)

### In-place Reversal of Linked List

How do I identify when to use this pattern:

- If you’re asked to reverse a linked list without using extra memory

Problems:

- Reverse a Sub-list (medium)
- Reverse every K-element Sub-list (medium)

### Tree BFS

How to identify the Tree BFS pattern:

- If you're asked to traverse a tree in a level-by-level fashion (or level order traversal)

Problems:

- Binary Tree Level Order Traversal (easy)
- Zigzag Traversal (medium)

### Tree DFS

How to identify the Tree DFS pattern:

- If you're asked to traverse a tree with in-order, preorder, or postorder DFS.
- If the problem requires searching for something where the node is closer to a leaf.

Problems:

- Sum of Path Numbers (medium)
- All Paths for a Sum (medium)

### Two Heap

Ways to identify the Two Heaps Pattern:

- Useful in situations like Priority Queue, Scheduling
- If the problem states that you need to find the smallest/largest/median elements of a set.
- Sometimes, useful in problems featuring a binary tree data structure.

Problems Featuring:

- Find the Median of a Number Stream (medium)

### Subsets

How to identify the Subsets Pattern:

- Problems where you need to find the combinations or permutations of a given set.

Problems:

- Subsets with Duplicates (easy)
- String Permutations by changing case (medium)

### Modified Binary Search

Problems:

- Order-agnostic Binary Search (easy)
- Search in Sorted Infinite Array (medium)

### Top 'K' elements

How to identify the Top 'K' Elements pattern:

- If you're asked to find the top/smallest/frequent 'K' elements of a given set
- If you're asked to sort an array to find an exact element

Problems featuring Top 'K' Elements pattern:

- Top 'K' Numbers (easy)
- Top 'K' Frequent Numbers (medium)

### K-way Merge

How to identify the K-way Merge patterns:

- The problem will feature sorted arrays, lists, or a matrix.
- If the problem asks you to merge sorted lists, find the smallest element in a sorted list.

Problems:

- Merge K Sorted Lists (medium)
- K Pairs with Largest Sums (Hard)

### Topological Sort

How to identify the Topological Sort patterns:

- The problem will deal with graphs that have no directed cycles.
- If you're asked to update all objects in a sorted order.
- If you have a class of objects that follow a particular order.

Problems:

- Task Scheduling (medium)
- Minimum height of a tree (hard)
