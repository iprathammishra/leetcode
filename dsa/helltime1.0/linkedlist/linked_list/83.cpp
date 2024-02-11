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
    ListNode *deleteDuplicates(ListNode *head)
    {
        set<int> lset;
        ListNode *temp = head;
        while (temp)
        {
            lset.insert(temp->val);
            temp = temp->next;
        }
        vector<int> lvec(lset.begin(), lset.end());
        sort(lvec.begin(), lvec.end());
        ListNode *hh = nullptr;
        ListNode *tt = nullptr;
        for (const int &i : lvec)
        {
            ListNode *newNode = new ListNode(i);
            if (!hh)
            {
                hh = newNode;
                tt = newNode;
            }
            else
            {
                tt->next = newNode;
                tt = newNode;
            }
        }
        return hh;
    }
};