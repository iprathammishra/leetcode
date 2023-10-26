// **Return Kth to Last:** Implement an algorithm to find the kth to last element of a singly linked list.
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
    void insertNodeAtEnd(int data);
    void displayNodes();
    Node *returnKth2Last(int k);
};
void LinkedList::insertNodeAtEnd(int data)
{
    Node *newNode = new Node(data);
    newNode->next = nullptr;
    if (head == nullptr)
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
Node *LinkedList::returnKth2Last(int k)
{
    if (!head || k <= 0)
        return nullptr;
    int length = 0; // Keep your variables declared otherwise segmentation fault will haunt you.
    Node *temp = head;
    while (temp)
    {
        length++;
        temp = temp->next;
    }
    temp = head;
    for (int i = 0; i < length - k; i++)
    {
        temp = temp->next;
    }
    return temp;
}
int main()
{
    LinkedList ll;
    ll.insertNodeAtEnd(1);
    ll.insertNodeAtEnd(2);
    ll.insertNodeAtEnd(3);
    ll.insertNodeAtEnd(4);
    ll.insertNodeAtEnd(5);
    ll.insertNodeAtEnd(6);
    ll.displayNodes();
    Node *kthNode = ll.returnKth2Last(4);
    cout << "Data: " << kthNode->data;
    return 0;
}