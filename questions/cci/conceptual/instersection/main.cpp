// **Intersection:** Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node. Note that the intersection is defined based on reference, not value. That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.
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
public:
    Node *head, *tail;
    LinkedList() : head(nullptr), tail(nullptr) {}
    Node *findIntersection(Node *l1, Node *l2)
    {
        Node *runner1 = l1;
        Node *runner2 = l2;

        while (runner1 != runner2)
        {
            runner1 = (runner1 == nullptr) ? l2 : runner1->next;
            runner2 = (runner2 == nullptr) ? l1 : runner2->next;
        }
        return runner1;
    }
    void insertNode(Node *n)
    {
        if (!head)
            head = tail = n;
        else
        {
            tail->next = n;
            tail = n;
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
};
int main()
{
    LinkedList ll1, ll2;
    Node *n1 = new Node(4);
    Node *n2 = new Node(2);
    Node *n3 = new Node(4);
    Node *n4 = new Node(6);
    Node *common = new Node(3);

    ll1.insertNode(n1);
    ll1.insertNode(n2);
    ll1.insertNode(common);

    ll2.insertNode(n3);
    ll2.insertNode(common);
    ll2.insertNode(n4);

    ll1.displayAllList();
    ll2.displayAllList();

    cout << "Intersection from node value: " << ll1.findIntersection(ll1.head, ll2.head)->data;

    return 0;
}