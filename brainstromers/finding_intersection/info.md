# Finding Intersection

Suppose we have given two variables storing some data (say text) data and we want to find a common intersection point between those two variables.
<br>
We can understand how to perform that using a LinkedList example.

```c++
struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};

// Function to find the intersection point of two linked lists
ListNode* findIntersection(ListNode* list1, ListNode* list2) {
    ListNode* p1 = list1;
    ListNode* p2 = list2;

    while (p1 != p2) {
        p1 = (p1 == nullptr) ? list2 : p1->next;
        p2 = (p2 == nullptr) ? list1 : p2->next;
    }

    return p1; // p1 (or p2) will be the intersection point, or nullptr if there's no intersection.
}
```

## Step-by-Step Explanation of `findIntersection` Function

This algorithm is efficient and works in O(m + n) time, where m and n are the lengths of the two linked lists.

```cpp
ListNode* findIntersection(ListNode* list1, ListNode* list2) {
    ListNode* p1 = list1;
    ListNode* p2 = list2;
```

- The `findIntersection` function takes two pointers an input: `list1` and `list2`, which represent the heads of the two linked lists you want to find the intersection for. It initializes two pointers, `p1` and `p2`, to the heads of `list1` and `list2`, respectively.

```cpp
while (p1 != p2) {
```

- The code enters a `while` loop, which continues until `p1` is equal to `p2`. This loop is used to traverse both linked lists simultaneously and compare their nodes.

```cpp
p1 = (p1 == nullptr) ? list2 : p1->next;
p2 = (p2 == nullptr) ? list1 : p2->next;
```

- In each iteration of the loop, two things happen:

1. `p1` and `p2` move to their next nodes. If `p1` is not `nullptr`, it advances to the next node in `list1` (via `p1->next`). If `p1` is `nullptr` (meaning it reached the end of `list1`), it is reassigned to `list2`, effectively "jumping" to the beginning of `list2`. Similarly, the same logic is applied to `p2`.
2. This effectively simulates the movement of the two pointers through both lists, ensuring they stay at the same relative positions in their respective lists.

```cpp
return p1; // p1 (or p2) will be the intersection point, or nullptr if there's no intersection.
```

- After the `while` loop, when `p1` is equal to `p2`, it means the two pointers have reached the intersection point of the linked lists. This intersection node is the node where the two linked lists share a common reference.
- If there's no intersection, both `p1` and `p2` will become `nullptr` simultaneously, and in that case, the function returns `nullptr` to indicate that there is no intersection.
