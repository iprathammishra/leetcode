// **Delete Middle Node:** Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.

// Example:
// Input: the node c from the linked list a->b->c->d->e->f
// Result: nothing is returned, but the new linked list looks like a->b->d->e->f
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
    void insertNodeatEnd(int data);
    void displayNodes();
    void deleteMiddleNode();
};
void LinkedList::insertNodeatEnd(int data)
{
    Node *newNode = new Node(data);
    newNode->next = nullptr;
    if (!head)
        head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
void LinkedList::displayNodes()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
void LinkedList::deleteMiddleNode()
{
    Node *current = head;
    Node *previous = nullptr;
    int length = 0;
    while (current)
    {
        length++;
        current = current->next;
    }
    current = head;
    for (int i = 0; i < length / 2; i++)
    {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    delete current;
}
int main()
{
    LinkedList ll;
    ll.insertNodeatEnd(1);
    ll.insertNodeatEnd(2);
    ll.insertNodeatEnd(3);
    ll.insertNodeatEnd(4);
    ll.insertNodeatEnd(5);
    ll.insertNodeatEnd(6);

    ll.displayNodes();
    ll.deleteMiddleNode();
    ll.displayNodes();
    return 0;
}