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
private:
    ListNode *reverseNode(ListNode *h)
    {
        ListNode *prev = nullptr;
        while (h)
        {
            ListNode *next = h->next;
            h->next = prev;
            prev = h;
            h = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slowPointer = head;
        ListNode *fastPointer = head;
        while (fastPointer && fastPointer->next)
        {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }
        slowPointer = reverseNode(slowPointer);
        while (slowPointer)
        {
            if (slowPointer->val != head->val)
                return false;
            head = head->next;
            slowPointer = slowPointer->next;
        }
        return true;
    }
};