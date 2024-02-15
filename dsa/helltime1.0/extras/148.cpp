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
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *otherPart = slow->next;
        slow->next = nullptr;
        ListNode *leftSide = sortList(head);
        ListNode *rightSide = sortList(otherPart);
        ListNode *dummy = new ListNode();
        ListNode *current = dummy;
        while (leftSide && rightSide)
        {
            if (leftSide->val <= rightSide->val)
            {
                current->next = leftSide;
                leftSide = leftSide->next;
            }
            else
            {
                current->next = rightSide;
                rightSide = rightSide->next;
            }
            current = current->next;
        }

        current->next = leftSide ? leftSide : rightSide;
        ListNode *sortedHead = dummy->next;
        delete dummy;
        return sortedHead;
    }
};