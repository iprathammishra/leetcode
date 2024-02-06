// Hare & Tortoise Algorithm ||Floyd's Cycle Detection Algorithm.
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
};

Node *head = NULL;
Node *tail = NULL;

class LinkedList
{
public:
    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool detectLoop()
    {
        Node *slowPointer = head;
        Node *fastPointer = head;
        while (!slowPointer && !fastPointer && !fastPointer->next)
        {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
            if (slowPointer == fastPointer)
                return true;
        }
        return false;
    }
};

int main()
{
    LinkedList l1;
    l1.insert(10);
    l1.insert(20);
    l1.insert(30);
    l1.insert(40);
    l1.insert(50);

    // Intentionally creating loop.
    Node *temp = head;
    while (!temp->next)
        temp = temp->next;
    temp->next = head;
}