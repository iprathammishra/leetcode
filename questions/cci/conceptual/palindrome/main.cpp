// **Palindrome:** Implement a function to check if a linked list is a palindrome.
#include <iostream>
#include <vector>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int val) : data(val), next(nullptr) {}
};
class LinkedList
{
public:
    ListNode *head, *tail;
    LinkedList() : head(nullptr), tail(nullptr) {}
    void insertNodeAtEnd(int data)
    {
        ListNode *newNode = new ListNode(data);
        if (!head)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    bool checkPalindrome(ListNode *n)
    {
        vector<int> m;
        LinkedList t;
        ListNode *current = n;
        ListNode *previous = nullptr;
        bool flag = true;
        while (current)
        {
            t.insertNodeAtEnd(current->data);
            current = current->next;
        }
        current = n;
        while (current)
        {
            if (current->next == nullptr && previous == nullptr)
            {
                m.push_back(current->data);
                delete current;
                break;
            }
            if (current->next == nullptr)
            {
                m.push_back(current->data);
                delete current;
                previous->next = nullptr;
                current = n;
                previous = nullptr;
            }
            else
            {
                previous = current;
                current = previous->next;
            }
        }
        ListNode *comp = t.head;
        for (int i = 0; i < m.size(); i++)
        {
            if (m[i] != comp->data)
                return false;
            comp = comp->next;
        }
        return true;
    }
};
int main()
{
    LinkedList ll;
    ll.insertNodeAtEnd(1);
    ll.insertNodeAtEnd(0);
    ll.insertNodeAtEnd(0);
    ll.insertNodeAtEnd(1);

    cout << ll.checkPalindrome(ll.head);
    return 0;
}