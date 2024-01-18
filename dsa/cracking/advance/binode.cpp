// 12. **BiNode:** Consider a simple data structure called BiNode, which has pointers to two other nodes.

// ```java
// public class BiNode {
//     public BiNode node1, node2;
//     public int data;
// }
// ```

// The data structure BiNode could be used to represent both a binary tree (where node1 is the left node and node2 is the right node) or a doubly linked list (where node1 is the previous node and node2 is the next node.) Implement a method to convert a binary search tree (implemented with BiNode) into a doubly linked list. The values should be kept in order and the operation should be performed in place (that is, on the original data structure).
#include <iostream>
#include <stack>
class BiNode
{
public:
    BiNode *left, *right;
    int data;
    BiNode(int value) : data(value), left(nullptr), right(nullptr) {}
};
class BinaryTreeToDoublyLinkedList
{
public:
    static BiNode *convertBSTToDLL(BiNode *root)
    {
        if (!root)
            return nullptr;
        BiNode *head = nullptr;
        BiNode *prev = nullptr;
        std::stack<BiNode *> stack;
        while (root || !stack.empty())
        {
            while (root)
            {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if (!prev)
                head = root;
            else
            {
                prev->right = root;
                root->left = prev;
            }
            prev = root;
            root = root->right;
        }
        return head;
    }
};
void printDLL(BiNode *head)
{
    while (head)
    {
        std::cout << head->data << " ";
        head = head->right;
    }
    std::cout << std::endl;
}
int main()
{
    BiNode *root = new BiNode(4);
    root->left = new BiNode(2);
    root->right = new BiNode(5);
    root->left->left = new BiNode(1);
    root->left->right = new BiNode(3);

    BiNode *head = BinaryTreeToDoublyLinkedList::convertBSTToDLL(root);

    std::cout << "Doubly Linked List: ";
    printDLL(head);

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

// https://chat.openai.com/share/84e08cbe-dbcf-4daf-a125-6d063122f4bb