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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return nullptr;
        ListNode *temp = head;
        vector<int> vec;
        while (temp)
        {
            vec.push_back(temp->val);
            temp = temp->next;
        }
        k %= vec.size();
        for (int i = 0; i < k; i++)
            rotate(vec.rbegin(), vec.rbegin() + 1, vec.rend());
        ListNode *hh = nullptr;
        ListNode *tt = nullptr;
        for (const int &i : vec)
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