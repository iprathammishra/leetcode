/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *current = root;
        Node *prev = nullptr;
        Node *nextLevelStart = nullptr;
        function<void(Node *)> connect = [&](Node *child) -> void
        {
            if (!child)
            {
                return;
            }
            if (!nextLevelStart)
            {
                nextLevelStart = child;
            }
            if (prev)
            {
                prev->next = child;
            }
            prev = child;
        };
        while (current)
        {
            prev = nextLevelStart = nullptr;
            while (current)
            {
                connect(current->left);
                connect(current->right);
                current = current->next;
            }
            current = nextLevelStart;
        }
        return root;
    }
};