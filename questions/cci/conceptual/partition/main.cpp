// **Partition:** Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. If x is contained within the list, the values of x only need to be after the elements less than x (see below). The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.

// Example:
// Input: 3->5->8->5->10->2->1 [partition = 5]
// Output: 3->1->2->10->5->5->8
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

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    void insertNodeAtFront(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head = newNode;
        }
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
    Node *partitionOfList(int partition)
    {
        if (!head)
            return nullptr;
        Node *current = head;
        LinkedList partedList;
        while (current)
        {
            if (current->data >= partition)
                partedList.insertNodeAtEnd(current->data);
            else if (current->data < partition)
                partedList.insertNodeAtFront(current->data);
            current = current->next;
        }
        return partedList.head;
    }
    void displayAllList(Node *h)
    {
        while (h)
        {
            cout << h->data << "->";
            h = h->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedList ll;
    ll.insertNodeAtEnd(3);
    ll.insertNodeAtEnd(5);
    ll.insertNodeAtEnd(8);
    ll.insertNodeAtEnd(5);
    ll.insertNodeAtEnd(10);
    ll.insertNodeAtEnd(2);
    ll.insertNodeAtEnd(1);

    Node *temp = ll.partitionOfList(5);
    ll.displayAllList(temp);
    return 0;
}