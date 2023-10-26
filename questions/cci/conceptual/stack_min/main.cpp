// **Stack Min:** How would you design a stack which, in addition to push and pop, has a function min which returns the minimum element? Push, pop, and min should all operate in O(1) time.
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
    int minV[1] = {0};

public:
    Stack() : top(nullptr) {}
    void push(int data);
    void pop();
    void displayAllStack();
    int min();
};
void Stack::push(int data)
{
    Node *newNode = new Node(data);
    if (!top)
    {
        top = newNode;
        minV[0] = newNode->data;
    }
    else
    {
        newNode->next = top;
        top = newNode;
        if (newNode->data <= minV[0])
            minV[0] = newNode->data;
    }
}
void Stack::pop()
{
    if (!top)
        return;
    Node *temp = top;
    top = top->next;
    delete temp;
}
void Stack::displayAllStack()
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
int Stack::min()
{
    return minV[0];
}
int main()
{
    Stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(-3);
    stk.push(4);
    stk.push(5);

    stk.displayAllStack();
    stk.pop();
    stk.displayAllStack();
    cout << "Minimum element: " << stk.min();
    return 0;
}