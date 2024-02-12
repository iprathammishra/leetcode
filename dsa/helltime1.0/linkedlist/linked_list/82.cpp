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
        ListNode *temp = head;
        vector<int> fvec;
        while (temp)
        {
            fvec.push_back(temp->val);
            temp = temp->next;
        }
        unordered_map<int, int> lmap;
        for (const int &i : fvec)
            lmap[i]++;
        fvec.clear();
        for (const auto &[i, j] : lmap)
            if (j == 1)
                fvec.push_back(i);
        sort(fvec.begin(), fvec.end());
        ListNode *hh = nullptr;
        ListNode *tt = nullptr;
        for (const int &i : fvec)
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