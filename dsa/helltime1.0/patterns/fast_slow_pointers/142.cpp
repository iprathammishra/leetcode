/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slowPointer = head;
        ListNode *fastPointer = head;
        bool cycle = false;
        while (slowPointer && fastPointer && fastPointer->next)
        {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
            if (slowPointer == fastPointer)
            {
                cycle = true;
                break;
            }
        }
        if (cycle)
        {
            slowPointer = head;
            while (slowPointer != fastPointer)
            {
                slowPointer = slowPointer->next;
                fastPointer = fastPointer->next;
            }
            return slowPointer;
        }
        else
            return nullptr;
    }
};