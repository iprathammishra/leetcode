/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto compare = [](ListNode *a, ListNode *b)
        { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(compare)> min_heap(compare);
        for (ListNode *list : lists)
        {
            if (list)
            {
                min_heap.push(list);
            }
        }
        ListNode *dummy = new ListNode();
        ListNode *current = dummy;
        while (!min_heap.empty())
        {
            ListNode *min_node = min_heap.top();
            min_heap.pop();
            if (min_node->next)
            {
                min_heap.push(min_node->next);
            }
            current->next = min_node;
            current = current->next;
        }
        return dummy->next;
    }
};