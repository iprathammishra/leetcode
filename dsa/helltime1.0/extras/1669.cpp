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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *prevNode = list1;
        ListNode *postNode = list1;
        for (int i = 0; i < a - 1; i++)
            prevNode = prevNode->next;
        for (int i = 0; i <= b; i++)
            postNode = postNode->next;
        prevNode->next = list2;
        while (prevNode->next)
            prevNode = prevNode->next;
        prevNode->next = postNode;
        return list1;
    }
};