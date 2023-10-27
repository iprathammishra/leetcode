// **Sum Lists:** You have numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

// Example:
// Input: (7->1->6) + (5->9->2). That is 617 + 295.
// Output: 2->1->9. That is, 912.
// Follow Up:
// Suppose the digits are stored in forward order. Repeat the above problem.
// Example:
// Input: (6->1->7) + (2->9->5). That is, 617 + 295.
// Output: 9->1->2. That is, 912.
#include <iostream>
#include <vector>
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
    vector<int> v1, v2;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    Node *returnRoot()
    {
        return head;
    }
    void insertNodeAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void deleteFromStart()
    {
        if (!head)
            return;
        Node *tempPtr = head;
        head = head->next;
        delete tempPtr;
    }
    void deleteFromEnd()
    {
        if (!head)
            return;
        Node *current = head;
        Node *previous = nullptr;
        while (current)
        {
            if (current->next == nullptr)
            {
                delete current;
                previous->next = nullptr; // Even though the memory is released to still need to point the previous node's next to a null pointer.
                tail = previous;
                break;
            }
            previous = current;
            current = previous->next;
        }
    }
    void displayAllList()
    {
        Node *tempPtr = head;
        while (tempPtr)
        {
            cout << tempPtr->data << "->";
            tempPtr = tempPtr->next;
        }
        cout << endl;
    }
    Node *returnSumForReverseOrderList(Node *l1, Node *l2)
    {
        Node *runner = l1;
        int length = 0;
        int carry = 0;
        while (runner)
        {
            v1.push_back(runner->data);
            runner = runner->next;
        }
        runner = l2;
        while (runner)
        {
            v2.push_back(runner->data);
            runner = runner->next;
        }
        if (v1.size() > v2.size())
        {
            length = v1.size();
            v2.insert(v2.begin(), (length - v2.size()), 0); // the lower end
        }
        else
        {
            length = v2.size();
            v1.insert(v1.end(), (length - v1.size()), 0); // the upper end
        }
        Node *secondHead = nullptr;
        Node *secondTail = nullptr;
        for (int i = 0; i < length; i++)
        {
            int addition = v1[i] + v2[i];
            if (carry == 0)
            {
                if (addition > 9)
                {
                    carry = 1;
                    Node *newNode = new Node(addition % 10);
                    if (!secondHead)
                        secondHead = secondTail = newNode;
                    else
                    {
                        secondTail->next = newNode;
                        secondTail = newNode;
                    }
                }
                else
                {
                    carry = 0;
                    Node *newNode = new Node(addition);
                    if (!secondHead)
                        secondHead = secondTail = newNode;
                    else
                    {
                        secondTail->next = newNode;
                        secondTail = newNode;
                    }
                }
            }
            else
            {
                if (addition > 9 || addition + 1 > 9)
                {
                    carry = 1;
                    Node *newNode = new Node((addition + 1) % 10);
                    if (!secondHead)
                        secondHead = secondTail = newNode;
                    else
                    {
                        secondTail->next = newNode;
                        secondTail = newNode;
                    }
                }
                else
                {
                    carry = 0;
                    Node *newNode = new Node(addition + 1);
                    if (!secondHead)
                        secondHead = secondTail = newNode;
                    else
                    {
                        secondTail->next = newNode;
                        secondTail = newNode;
                    }
                }
            }
        }
        if (carry == 1)
        {
            Node *newNode = new Node(1);
            secondTail->next = newNode;
            secondTail = newNode;
        }
        v1.clear();
        v2.clear();
        return secondHead;
    }
    Node *returnSumForForwardOrderList(Node *l1, Node *l2)
    {
        Node *runner = l1;
        int length = 0;
        int carry = 0;
        while (runner)
        {
            v1.insert(v1.begin(), 1, runner->data);
            runner = runner->next;
        }
        runner = l2;
        while (runner)
        {
            v2.insert(v2.begin(), 1, runner->data);
            runner = runner->next;
        }
        if (v1.size() > v2.size())
        {
            length = v1.size();
            v2.insert(v2.begin(), (length - v2.size()), 0); // the lower end
        }
        else
        {
            length = v2.size();
            v1.insert(v1.end(), (length - v1.size()), 0); // the upper end
        }
        Node *secondHead = nullptr;
        Node *secondTail = nullptr;
        for (int i = 0; i < length; i++)
        {
            int addition = v1[i] + v2[i];
            if (carry == 0)
            {
                if (addition > 9)
                {
                    carry = 1;
                    Node *newNode = new Node(addition % 10);
                    if (!secondHead)
                        secondHead = secondTail = newNode;
                    else
                    {
                        newNode->next = secondHead;
                        secondHead = newNode;
                    }
                }
                else
                {
                    carry = 0;
                    Node *newNode = new Node(addition);
                    if (!secondHead)
                        secondHead = secondTail = newNode;
                    else
                    {
                        newNode->next = secondHead;
                        secondHead = newNode;
                    }
                }
            }
            else
            {
                if (addition > 9 || addition + 1 > 9)
                {
                    carry = 1;
                    Node *newNode = new Node((addition + 1) % 10);
                    if (!secondHead)
                        secondHead = secondTail = newNode;
                    else
                    {
                        newNode->next = secondHead;
                        secondHead = newNode;
                    }
                }
                else
                {
                    carry = 0;
                    Node *newNode = new Node(addition + 1);
                    if (!secondHead)
                        secondHead = secondTail = newNode;
                    else
                    {
                        newNode->next = secondHead;
                        secondHead = newNode;
                    }
                }
            }
        }
        if (carry == 1)
        {
            Node *newNode = new Node(1);
            newNode->next = secondHead;
            secondHead = newNode;
        }
        v1.clear();
        v2.clear();
        return secondHead;
    }
};
int main()
{
    LinkedList ll, ll1, ll2, ll3, ll4;

    ll1.insertNodeAtEnd(7);
    ll1.insertNodeAtEnd(1);
    ll1.insertNodeAtEnd(6);

    ll2.insertNodeAtEnd(5);
    ll2.insertNodeAtEnd(9);
    ll2.insertNodeAtEnd(2);

    ll3.insertNodeAtEnd(6);
    ll3.insertNodeAtEnd(1);
    ll3.insertNodeAtEnd(7);

    ll4.insertNodeAtEnd(2);
    ll4.insertNodeAtEnd(9);
    ll4.insertNodeAtEnd(5);

    Node *r = ll.returnSumForReverseOrderList(ll1.returnRoot(), ll2.returnRoot());
    Node *f = ll.returnSumForForwardOrderList(ll3.returnRoot(), ll4.returnRoot());
    while (r)
    {
        cout << r->data << "->";
        r = r->next;
    }
    cout << endl;
    while (f)
    {
        cout << f->data << "->";
        f = f->next;
    }
    cout << endl;
    return 0;
}