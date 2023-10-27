// **Loop Detection:** Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.

// Definition:
// Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list.

// Example:
// Input: A->B->C->D->E->C [the same C as earlier]
// Output: C
#include <iostream>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int val) : data(val), next(nullptr) {}
};
ListNode *detectLoop(ListNode *n)
{
    ListNode *p1, *p2;
    p1 = p2 = n;
    while (p1 && p1->next)
    {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2)
            break;
    }

    if (!p1 || !p1->next)
        return nullptr;
    p1 = n;
    while (p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}
int main()
{
    ListNode *A = new ListNode(1);
    ListNode *B = new ListNode(2);
    ListNode *C = new ListNode(3);
    ListNode *D = new ListNode(4);
    ListNode *E = new ListNode(5);
    ListNode *F = new ListNode(6);

    A->next = B;
    B->next = C;
    C->next = B;
    D->next = E;
    E->next = F;
    F->next = C;

    cout << "Loop starts from: " << detectLoop(A)->data;

    return 0;
}