// **Three in One:** Describe how you could use a singly array to implement three stacks.
// Creating 3 stacks from a given integer array. 1. Prime Numbers, 2. Even Numbers, 3. Odd Numbers.
#include <iostream>
using namespace std;
const int arr[21] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15,
    16,
    17,
    18,
    19,
    20};
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
    int choice;
    void allPrime();
    void allEven();
    void allOdd();

public:
    Stack(int choice) : top(nullptr)
    {
        switch (choice)
        {
        case 1:
            allPrime();
            break;
        case 2:
            allEven();
            break;
        case 3:
            allOdd();
            break;
        default:
            cout << "Invalid response.";
            exit(1);
            break;
        }
    }
    void displayEntireStack();
    void pop();
    void peek();
};
void Stack::allPrime()
{
    for (int i : arr)
    {
        if (i < 2)
            continue;
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            Node *newNode = new Node(i);
            if (!top)
                top = newNode;
            else
            {
                newNode->next = top;
                top = newNode;
            }
        }
    }
}
void Stack::allEven()
{
    for (int i : arr)
        if (i % 2 == 0 && i != 0)
        {
            Node *newNode = new Node(i);
            if (!top)
                top = newNode;
            else
            {
                newNode->next = top;
                top = newNode;
            }
        }
}
void Stack::allOdd()
{
    for (int i : arr)
        if (i % 2 != 0 && i != 0)
        {
            Node *newNode = new Node(i);
            if (!top)
                top = newNode;
            else
            {
                newNode->next = top;
                top = newNode;
            }
        }
}
void Stack::displayEntireStack()
{
    Node *current = top;
    while (current)
    {
        cout << current->data << "<-";
        current = current->next;
    }
    cout << endl;
}
void Stack::pop()
{
    if (!top)
        return;
    Node *temp = top;
    temp = top->next;
    delete top;
    top = temp;
}
void Stack::peek()
{
    if (!top)
        return;
    cout << top->data << endl;
}
int main()
{
    Stack stk1(2);
    stk1.displayEntireStack();
    stk1.pop();
    stk1.peek();
    Stack stk2(3);
    stk2.displayEntireStack();
    Stack stk3(1);
    stk3.displayEntireStack();
    return 0;
}

// 75: This is a loop that starts with `j` equals to 2 and continues until `j` squared (j*j) exceeds `i`, further testing is unnessary beacuse if `i` has a divisor larger than its square root, it must also have a corresponding factor smaller than its square root.