## `More` along-the-way questions.

### See the code below and try to find the problem.

```cpp
void deleteHead()
{
    if (!head)
        return;
    head = head->right;
    delete head->left;
}
void deleteTail()
{
    if (!head)
        return;
    tail = tail->left;
    delete tail->right;
}
```

There is a problem in both `deleteHead` and `deleteTail` functions. After you update `head` or `tail`, you are trying to delete the old `head` or `tail`, but you have lost the reference to them. Also, you are not updating the `left` pointer of the new `head` or the `right` pointer of the new `tail` to `nullptr`.

Here's the corrected code:

```cpp
void deleteHead()
{
    if (!head)
        return;
    ListNode* temp = head;
    head = head->right;
    if (head) // Check if head is not nullptr
        head->left = nullptr;
    delete temp;
}

void deleteTail()
{
    if (!head)
        return;
    ListNode* temp = tail;
    tail = tail->left;
    if (tail) // Check if tail is not nullptr
        tail->right = nullptr;
    delete temp;
}
```

In this corrected version, a temporary pointer is used to hold the old `head` or `tail` before updating `head` or `tail`. Then, the old `head` or `tail` is deleted using the temporary pointer. Also, the `left` pointer of the new `head` or the `right` pointer of the new `tail` is updated to `nullptr`.

### `Follow Up:` Why did we use need to update the `left` pointer to the new `head` and the `right` pointer of the new `tail` to `nullptr`? Also, why did we use the temporary pointer for deletion, can't we use directly delete without using a temporary pointer?

This is because, in a doubly linked list, the `left` pointer of the head and the `right` pointer of the tail should always be `nullptr`.

As for the use of the temporary pointer, it's necessary because once you update the `head` or `tail` pointer, you lose the reference to the old `head` or `tail` node. If you try to delete the old `head` or `tail` after updating the `head` or `tail` pointer, you would not be properly deleting them from the memory. The temporary pointer allows you to keep a reference to the old `head` or `tail` so you can properly delete it.
