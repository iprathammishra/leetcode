auto compare = [](ListNode *a, ListNode *b)
{
    return a->val > b->val;
};

// Define a priority queue with the custom comparator to keep track of the nodes.
priority_queue<ListNode *, vector<ListNode *>, decltype(compare)> min_heap(compare);

// Add the first node of each list to the priority queue if it is not null.
for (ListNode *list_head : lists)
{
    if (list_head)
    {
        min_heap.push(list_head);
    }
}