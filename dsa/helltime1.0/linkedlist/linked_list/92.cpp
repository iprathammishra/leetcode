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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || left == right)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *preReversed = dummy;
        for (int i = 0; i < left - 1; i++)
            preReversed = preReversed->next;
        ListNode *current = preReversed->next;
        ListNode *prev = nullptr;
        ListNode *nextNode = nullptr;
        for (int i = 0; i < right - left + 1; i++)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        preReversed->next->next = current;
        preReversed->next = prev;
        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};