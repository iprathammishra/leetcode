// Design algorithms for the following operations for a node v in a binary tree T:

// preOrderNext(v): return the node visited after v in a preorder traversal of T.
// inOrderNext(v): return the node visited after v in an inorder traversal of T.
// postOrderNext(v): return the node visited after v in a postorder traversal of T.

#include <iostream>
#include <stack>
#include <vector>
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
class BST
{
private:
    TreeNode *root;

public:
    BST() : root(nullptr) {}
    void insertTreeNodeInBST(TreeNode *value)
    {
        TreeNode *newNode = new TreeNode(value->data);
        if (!root)
        {
            root = newNode;
            return;
        }
        TreeNode *runner = root;
        while (true)
            if (value->data < runner->data)
            {
                if (!runner->left)
                {
                    runner->left = newNode;
                    return;
                }
                runner = runner->left;
            }
            else
            {
                if (!runner->right)
                {
                    runner->right = newNode;
                    return;
                }
                runner = runner->right;
            }
    }
    bool deleteTreeNodeInBST(TreeNode *value)
    {
        if (!root)
            return false;
        TreeNode *runner = root;
        TreeNode *parent = nullptr;
        while (runner && runner->data != value->data)
        {
            parent = runner;
            if (value->data < runner->data)
                runner = runner->left;
            else
                runner = runner->right;
        }
        if (!runner)
            return false;
        if (!runner->left)
        {
            if (!parent)
                root = runner->right;
            else if (parent->left == runner)
                parent->left = runner->right;
            else
                parent->right = runner->right;
            delete runner;
        }
        else if (!runner->right)
        {
            if (!parent)
                root = runner->left;
            else if (parent->left == runner)
                parent->left = runner->left;
            else
                parent->right = runner->left;
            delete runner;
        }
        else
        {
            TreeNode *successor = runner->right;
            parent = runner;
            while (successor->left)
            {
                parent = successor;
                successor = successor->left;
            }
            runner->data = successor->data;
            if (parent->left == successor)
                parent->left = successor->right;
            else
                parent->right = successor->right;
            delete successor;
        }
        return true;
    }
    void inOrderIterativeTraversalOfBST()
    {
        if (!root)
            return;
        TreeNode *runner = root;
        std::stack<TreeNode *> s;
        while (runner || !s.empty())
        {
            while (runner)
            {
                s.push(runner);
                runner = runner->left;
            }
            runner = s.top();
            s.pop();
            std::cout << runner->data << " ";
            runner = runner->right;
        }
    }
    TreeNode *inOrderNext(TreeNode *v) {}
    TreeNode *preOrderNext(TreeNode *v) {}
    TreeNode *postOrderNext(TreeNode *v) {}
};
int main()
{

    return 0;
}