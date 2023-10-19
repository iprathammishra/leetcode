#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Stack
{
public:
    Node *top;
    Stack()
    {
        top = NULL;
    }
    void push(int data);
    void pop();
    int peek();
    void display();
};
void Stack::push(int n)
{
    Node *newNode = new Node();
    newNode->data = n;
    if (top == NULL)
        newNode->next = NULL;
    else
        newNode->next = top;
    top = newNode;
}
void Stack::pop()
{
    Node *temp;
    if (top == NULL)
    {
        cout << "Stack Underflow." << endl;
        return;
    }
    temp = top;
    top = top->next;
    delete temp;
}
int Stack::peek()
{
    if (top == NULL)
    {
        cout << "\nStack Underflow.";
        return -1;
    }
    return top->data;
}
void Stack::display()
{
    Node *temp;
    if (top == NULL)
        cout << "\nStack Underflow.";
    else
    {
        temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}
int main()
{
    Stack stk;
    stk.push(30);
    stk.push(20);
    stk.push(50);
    stk.push(70);
    stk.display();
    stk.pop();
    int top_value = stk.peek();
    if (top_value != -1)
        cout << "\nTop value is: " << top_value << "\n";
    cout << "Elements after the pop operation: \n";
    stk.display();
    return 0;
}