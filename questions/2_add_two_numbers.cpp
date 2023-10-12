/*
Description:
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/
#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        vector<int> nodeV;
        ListNode *l3 = new ListNode;
        int carry = 0;
        int placeholder = 0;
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 == NULL)
            {
                if (carry != 0)
                {
                    if (l2->val + placeholder + carry > 9)
                    {
                        // cout << (l2->val + placeholder + carry) % 10 << " ";
                        nodeV.push_back((l2->val + placeholder + carry) % 10);
                        carry = 1;
                    }
                    else
                    {
                        // cout << (l2->val + placeholder + carry) << " ";
                        nodeV.push_back((l2->val + placeholder + carry));
                        carry = 0;
                    }
                }
                else
                {
                    // cout << (l2->val + placeholder) << " ";
                    nodeV.push_back((l2->val + placeholder));
                    carry = 0;
                }
                l2 = l2->next;
            }
            else if (l2 == NULL)
            {
                if (carry != 0)
                {
                    if (l1->val + placeholder + carry > 9)
                    {
                        // cout << (l1->val + placeholder + carry) % 10 << " ";
                        nodeV.push_back((l1->val + placeholder + carry) % 10);
                        carry = 1;
                    }
                    else
                    {
                        // cout << (l1->val + placeholder + carry) << " ";
                        nodeV.push_back((l1->val + placeholder + carry));
                        carry = 0;
                    }
                }
                else
                {
                    // cout << (l1->val + placeholder) << " ";
                    nodeV.push_back((l1->val + placeholder));
                    carry = 0;
                }
                l1 = l1->next;
            }
            else
            {
                if (l1->val + l2->val > 9)
                {
                    if (carry != 0)
                    {
                        if (l1->val + l2->val + carry > 9)
                        {
                            // cout << (l1->val + l2->val + carry) % 10 << " ";
                            nodeV.push_back((l1->val + l2->val + carry) % 10);
                            carry = 1;
                        }
                        else
                        {
                            // cout << (l1->val + l2->val + carry) << " ";
                            nodeV.push_back((l1->val + l2->val + carry));
                            carry = 0;
                        }
                    }
                    else
                    {
                        // cout << (l1->val + l2->val) % 10 << " ";
                        nodeV.push_back((l1->val + l2->val) % 10);
                        carry = 1;
                    }
                }
                else
                {
                    if (carry != 0)
                    {
                        if (l1->val + l2->val + carry > 9)
                        {
                            // cout << (l1->val + l2->val + carry) % 10 << " ";
                            nodeV.push_back((l1->val + l2->val + carry) % 10);
                            carry = 1;
                        }
                        else
                        {
                            // cout << (l1->val + l2->val + carry) << " ";
                            nodeV.push_back((l1->val + l2->val + carry));
                            carry = 0;
                        }
                    }
                    else
                    {
                        // cout << (l1->val + l2->val) << " ";
                        nodeV.push_back((l1->val + l2->val));
                        carry = 0;
                    }
                }
                l1 = l1->next;
                l2 = l2->next;
            }
        }

        if (carry != 0)
        {
            // cout << 1;
            nodeV.push_back(1);
        }

        ListNode *head, *tail;
        head = NULL;
        tail = NULL;

        for (int element : nodeV)
        {
            ListNode *temp = new ListNode;
            temp->val = element;
            temp->next = NULL;
            if (head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }

        return head;
    }
};