// **Sort Stack:** Write a program to sort a stack such that the smallest items are on the top. You can use an additional temporary stack, but you may not copy the elements into any other data structure (such as an array). The stack supports the following operations: push, peek, and isEmpty.
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
    void push(int data);
    int peek();
    void pop();
    bool isEmpty();
    void displayOriginal();
    void displaySorted();
};
void Stack::push(int data)
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
int Stack::peek()
{
    if (!top)
        return -1;
    return top->data;
}
void Stack::pop()
{
    Node *temp = top;
    top = top->next;
    delete temp;
}
bool Stack::isEmpty()
{
    if (!top)
        return true;
    return false;
}
void Stack::displayOriginal()
{
    if (!top)
        return;
    Node *temp = top;
    while (temp)
    {
        cout << temp->data << "<-";
        temp = temp->next;
    }
    cout << endl;
}
void Stack::displaySorted()
{
    Stack tempStack;
    while (!isEmpty())
    {
        int temp = peek();
        pop();

        while (!tempStack.isEmpty() && tempStack.peek() > temp)
        {
            push(tempStack.peek());
            tempStack.pop();
        }
        tempStack.push(temp);
    }
    while (!tempStack.isEmpty())
    {
        push(tempStack.peek());
        tempStack.pop();
    }

    displayOriginal();
}
int main()
{
    Stack stk;
    stk.push(3);
    stk.push(4);
    stk.push(1);
    stk.push(2);
    stk.push(5);

    cout << stk.peek() << endl;
    cout << stk.isEmpty() << endl;

    stk.displayOriginal();
    stk.displaySorted();
    return 0;
}