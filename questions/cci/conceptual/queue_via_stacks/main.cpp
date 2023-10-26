// **Queue via Stacks:** Implement a queue using two stacks.
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {}
    void push(int data)
    {
        Node *newNode = new Node(data);
        if (!top)
            top = newNode;
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }
    void pop()
    {
        if (!top)
            return;
        Node *tempPtr = top;
        top = top->next;
        delete tempPtr;
    }
    bool isEmpty()
    {
        if (!top)
            return true;
        return false;
    }
    int peek()
    {
        if (!top)
            return -1;
        return top->data;
    }
    void displayAllStack()
    {
        if (!top)
            return;
        Node *tempPtr = top;
        while (tempPtr)
        {
            cout << tempPtr->data << "<-";
            tempPtr = tempPtr->next;
        }
        cout << endl;
    }
};
class Queue
{
private:
    Node *front, *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}
    void enQueueWithStacks(Stack stk1, Stack stk2)
    {
        while (!stk1.isEmpty())
        {
            int temp = stk1.peek();
            stk1.pop();
            Node *newNode = new Node(temp);
            if (!front)
                front = rear = newNode;
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
        }
        while (!stk2.isEmpty())
        {
            int temp = stk2.peek();
            stk2.pop();
            Node *newNode = new Node(temp);
            if (!front)
                front = rear = newNode;
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
        }
    }
    void deQueue()
    {
        if (front == rear)
            front = rear = nullptr;
        else
        {
            Node *tempPtr = front;
            front = front->next;
            delete tempPtr;
        }
    }
    void displayAllQueue()
    {
        if (!front)
            return;
        Node *tempPtr = front;
        while (tempPtr)
        {
            cout << tempPtr->data << "<<";
            tempPtr = tempPtr->next;
        }
        cout << endl;
    }
};
int main()
{
    Stack stk1, stk2;
    stk1.push(1);
    stk1.push(2);
    stk1.push(3);

    stk2.push(4);
    stk2.push(5);
    stk2.push(6);

    stk1.displayAllStack();
    stk2.displayAllStack();

    Queue myQueue;
    myQueue.enQueueWithStacks(stk1, stk2);
    myQueue.displayAllQueue();
    myQueue.deQueue();
    myQueue.displayAllQueue();
    return 0;
}