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
    ListNode *removeNodes(ListNode *head)
    {
        vector<int> values;
        vector<int> stack;
        while (head)
        {
            values.emplace_back(head->val);
            head = head->next;
        }
        for (const int &value : values)
        {
            while (!stack.empty() && stack.back() < value)
            {
                stack.pop_back();
            }
            stack.push_back(value);
        }
        ListNode *dummy_head = new ListNode();
        ListNode *current = dummy_head;
        for (const int &value : stack)
        {
            current->next = new ListNode(value);
            current = current->next;
        }
        return dummy_head->next;
    }
};