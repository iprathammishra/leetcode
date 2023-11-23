// A double-ended queue, or deque, is a list that allows for insertions and removals at either its head or its tail. Describe a way to implement a deque using a doubly linked list, so that every operation runs in O(1) time.
#include <iostream>
class ListNode
{
public:
    int data;
    ListNode *left, *right;
    ListNode(int val) : data(val), left(nullptr), right(nullptr){};
};
class DLLcDeque
{
private:
    ListNode *head, *tail;

public:
    DLLcDeque() : head(nullptr), tail(nullptr){};
    void insertListNodeAtHead(int value)
    {
        ListNode *newNode = new ListNode(value);
        if (!head)
        {
            head = newNode;
            return;
        }
        newNode->right = head;
        head->left = newNode;
        head = newNode;
        return;
    }
    void insertListNodeAtTail(int value)
    {
        ListNode *newNode = new ListNode(value);
        if (!head)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->right = newNode;
        newNode->left = tail;
        tail = newNode;
        return;
    }
    void displayListNodes()
    {
        if (!head)
            return;
        ListNode *runner = head;
        while (runner)
        {
            std::cout << runner->data << " ";
            runner = runner->right;
        }
    }
    void deleteHead()
    {
        if (!head)
            return;
        ListNode *temp = head;
        head = head->right;
        if (head)
            head->left = nullptr;
        delete temp;
    }
    void deleteTail()
    {
        if (!head)
            return;
        ListNode *temp = tail;
        tail = tail->left;
        if (tail)
            tail->right = nullptr;
        delete temp;
    }
};
int main()
{
    DLLcDeque dllObj;
    dllObj.insertListNodeAtTail(2);
    dllObj.insertListNodeAtTail(3);
    dllObj.insertListNodeAtTail(1);
    dllObj.insertListNodeAtTail(4);
    dllObj.insertListNodeAtTail(5);
    dllObj.insertListNodeAtHead(-2);
    dllObj.insertListNodeAtHead(-3);
    dllObj.insertListNodeAtHead(-1);
    dllObj.insertListNodeAtHead(-4);
    dllObj.insertListNodeAtHead(-5);
    dllObj.displayListNodes();
    std::cout << std::endl;
    dllObj.deleteHead();
    dllObj.deleteTail();
    dllObj.displayListNodes();
    return 0;
}