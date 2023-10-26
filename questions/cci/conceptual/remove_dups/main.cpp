// **Remove Dups:** Write code to remove duplicates from an unsorted linked list.
#include <iostream>
#include <unordered_set>
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
    void insertNodeAtEnd(int data);
    void eradicateDuplicates();
    void displayNodes();
};
void LinkedList::insertNodeAtEnd(int data)
{
    Node *newNode = new Node(data);
    newNode->next = nullptr;
    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
void LinkedList::displayNodes()
{
    Node *point = head;
    while (point)
    {
        cout << point->data << "->";
        point = point->next;
    }
    cout << endl;
}
void LinkedList::eradicateDuplicates()
{
    if (!head)
        return;
    unordered_set<int> uniqueElements;
    Node *current = head;
    Node *previous = nullptr;
    while (current)
    {
        if (uniqueElements.find(current->data) != uniqueElements.end())
        {
            previous->next = current->next;
            delete current;
        }
        else
        {
            uniqueElements.insert(current->data);
            previous = current;
        }
        current = previous->next; // Just because we are deleting current here we need to make current equal to previous->next.
    }
}
int main()
{
    LinkedList ll;
    ll.insertNodeAtEnd(1);
    ll.insertNodeAtEnd(2);
    ll.insertNodeAtEnd(3);
    ll.insertNodeAtEnd(3);
    ll.insertNodeAtEnd(4);
    ll.insertNodeAtEnd(5);
    ll.insertNodeAtEnd(5);
    ll.insertNodeAtEnd(5);
    ll.insertNodeAtEnd(5);
    ll.insertNodeAtEnd(6);

    ll.displayNodes();

    ll.eradicateDuplicates();

    ll.displayNodes();
    return 0;
}