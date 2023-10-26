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
            break;
        }
    }
    void displayEntireStack();
    void pop();
    void peek();
};
int main()
{
    Stack stk1(1);
    Stack stk2(1);
    Stack stk3(2);
    Stack stk4(3);
    Stack stk5(7);

    return 0;
}