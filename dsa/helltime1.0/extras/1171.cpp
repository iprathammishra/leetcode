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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        int prefixSum = 0;
        ListNode *dummy = new ListNode(0, head);
        map<int, ListNode *> lastSeenPrefixSum;
        ListNode *current = dummy;
        while (current)
        {
            prefixSum += current->val;
            lastSeenPrefixSum[prefixSum] = current;
            current = current->next;
        }
        prefixSum = 0;
        current = dummy;
        while (current)
        {
            prefixSum += current->val;
            current->next = lastSeenPrefixSum[prefixSum]->next;
            current = current->next;
        }
        return dummy->next;
    }
};