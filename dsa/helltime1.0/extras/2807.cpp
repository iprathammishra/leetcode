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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        ListNode *currentNode = head;
        ListNode *nextNode = head->next;
        while (nextNode)
        {
            int gcdValue = gcd(currentNode->val, nextNode->val);
            currentNode->next = new ListNode(gcdValue, nextNode);
            currentNode = nextNode;
            nextNode = nextNode->next;
        }
        return head;
    }
};