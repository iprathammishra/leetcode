# Detection of the Node that is Creating a Cyclic LinkedList or Creating a Loop in the LinkedList (Cycle Detection Algorithm)

To detect and return the node at the beginning of a loop in a circular linked list, you can use `Floyd's Tortoise` and `Hare Algorithm`, also known as the Cycle Detection algorithm.

```cpp
ListNode *detectLoop(ListNode *n)
{
    ListNode *p1, *p2;
    p1 = p2 = n;
    while (p1 && p1->next)
    {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2)
            break;
    }

    if (!p1 || !p1->next)
        return nullptr;
    p1 = n;
    while (p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}
```

In this code, we use two pointers, `p1` and `p2`, to traverse the linked list. If there is a loop, they will eventually meet at some point within the loop. Then, we move one of the pointers back to the head of the list and continue moving both pointers until they meet again. The meeting point is the beginning of the loop.

**Interviewer:** Can you explain the `detectCycle` method in detail?

**You:** Certainly! The `detectCycle` method is designed to detect and return the node at the beginning of a loop in a circular linked list. This problem is commonly solved using `Floyd's Tortoise and Hare algorithm`, also known as the Cycle Detection Algorithm. Let me walk you through the code step by step.

**You:** First, we check if the input `head` is either `nullptr` or if there's only one node in the list, which implies there cannot be a loop. In such cases, we return `nullptr` to indicate that there's no loop.

**You:** Now, we have two pointers, `p1` and `p2`, initially pointing to the `head` of the linked list. We then enter a loop where we move `p1` one step at a time and `p2` two steps at a time. This process continues until either `p2` reaches the end of the list or `p2` catches up with `p1`, indicating the presence of a loop.

**You:** If there's no loop (the loop exits without the pointers meeting), we return `nullptr` to indicate that there's no loop in the linked list.

**You:** However, if the pointers `p1` and `p2` do meet, it means there is a loop. We move one of the pointers, say `p1`, back to the `head` of the list while keeping the other pointer, `p2`, at the meeting point. Now, we move both pointers one step at a time until they meet again. The meeting point is the start of the loop.

**You:** Finally, we return the node where the loop begins, which is stored in either `p1` or `p2`. This effectively identifies and returns the node at the beginning of the loop in the circular linked list.
