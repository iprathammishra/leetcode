#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{
    Node *head, *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void insertNodeAtFront(int value);
    void display();
};
void LinkedList::insertNodeAtFront(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        return;
    }
}
void LinkedList::display()
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    LinkedList l1;
    l1.insertNodeAtFront(1);
    l1.insertNodeAtFront(2);
    l1.insertNodeAtFront(3);

    LinkedList l2;
    l2.insertNodeAtFront(4);
    l2.insertNodeAtFront(5);
    l2.insertNodeAtFront(6);

    return 0;
}