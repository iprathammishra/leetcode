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
    pair<ListNode *, ListNode *> reverse(ListNode *start, ListNode *end)
    {
        ListNode *current = start;
        ListNode *prev = end->next;
        while (prev != end)
        {
            ListNode *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return {end, start};
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *predecessor = dummy;
        while (head)
        {
            ListNode *tail = predecessor;
            for (int i = 0; i < k; i++)
            {
                tail = tail->next;
                if (!tail)
                    return dummy->next;
            }
            ListNode *nextGroupHead = tail->next;
            auto reversed = reverse(head, tail);

            predecessor->next = reversed.first;
            reversed.second->next = nextGroupHead;

            predecessor = reversed.second;
            head = nextGroupHead;
        }
        return dummy->next;
    }
};