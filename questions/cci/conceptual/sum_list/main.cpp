// **Sum Lists:** You have numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

// Example:
// Input: (7->1->6) + (5->9->2). That is 617 + 295.
// Output: 2->1->9. That is, 912.
// Follow Up:
// Suppose the digits are stored in forward order. Repeat the above problem.
// Example:
// Input: (6->1->7) + (2->9->5). That is, 617 + 295.
// Output: 9->1->2. That is, 912.
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList
{
private:
    Node *head, *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    Node *returnRoot()
    {
        return head;
    }
    void insertNodeAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void deleteFromStart()
    {
        if (!head)
            return;
        Node *tempPtr = head;
        head = head->next;
        delete tempPtr;
    }
    void deleteFromEnd()
    {
        if (!head)
            return;
        Node *current = head;
        Node *previous = nullptr;
        while (current)
        {
            if (current->next == nullptr)
            {
                delete current;
                previous->next = nullptr; // Even though the memory is released to still need to point the previous node's next to a null pointer.
                tail = previous;
                break;
            }
            previous = current;
            current = previous->next;
        }
    }
    void displayAllList()
    {
        Node *tempPtr = head;
        while (tempPtr)
        {
            cout << tempPtr->data << "->";
            tempPtr = tempPtr->next;
        }
        cout << endl;
    }
    Node *returnSumForReverseOrderList(Node *l1, Node *l2) {}
    Node *returnSumForForwardOrderList(Node *l1, Node *l2) {}
};
int main()
{
    LinkedList ll, ll1, ll2, ll3, ll4;

    ll1.insertNodeAtEnd(7);
    ll1.insertNodeAtEnd(1);
    ll1.insertNodeAtEnd(6);

    ll2.insertNodeAtEnd(5);
    ll2.insertNodeAtEnd(9);
    ll2.insertNodeAtEnd(2);

    ll3.insertNodeAtEnd(6);
    ll3.insertNodeAtEnd(1);
    ll3.insertNodeAtEnd(7);

    ll4.insertNodeAtEnd(2);
    ll4.insertNodeAtEnd(9);
    ll4.insertNodeAtEnd(5);

    Node *r = ll.returnSumForReverseOrderList(ll1.returnRoot(), ll2.returnRoot());
    Node *f = ll.returnSumForForwardOrderList(ll3.returnRoot(), ll4.returnRoot());
    while (r)
    {
        cout << r->data << "->";
        r = r->next;
    }
    cout << endl;
    while (f)
    {
        cout << f->data << "->";
        f = f->next;
    }
    cout << endl;
    return 0;
}