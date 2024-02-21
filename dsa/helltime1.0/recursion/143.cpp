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
    void reorderList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
        {
            return;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *second_half = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;
        while (second_half)
        {
            ListNode *next = second_half->next;
            second_half->next = prev;
            prev = second_half;
            second_half = next;
        }
        ListNode *first_half_head = head;
        ListNode *second_half_head = prev;
        while (second_half_head)
        {
            ListNode *next = second_half_head->next;
            second_half_head->next = first_half_head->next;
            first_half_head->next = second_half_head;

            first_half_head = second_half_head->next;
            second_half_head = next;
        }
    }
};