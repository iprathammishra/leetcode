#include <iostream>
#include <stack>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
void preOrderTraversal(TreeNode *root)
{
    if (!root)
        return;
    TreeNode *runner = root;
    stack<TreeNode *> s;
    s.push(runner);
    while (!s.empty())
    {
        runner = s.top();
        s.pop();
        cout << runner->data << " ";
        if (runner->right)
            s.push(runner->right);
        if (runner->left)
            s.push(runner->left);
    }
}
void inOrderTraversal(TreeNode *root)
{
    if (!root)
        return;
    TreeNode *runner = root;
    stack<TreeNode *> s;
    while (runner || !s.empty())
    {
        while (runner)
        {
            s.push(runner);
            runner = runner->left;
        }
        runner = s.top();
        s.pop();
        cout << runner->data << " ";
        runner = runner->right;
    }
}
void postOrderTraversal(TreeNode *root)
{
    if (!root)
        return;
    TreeNode *runner = root;
    stack<TreeNode *> s1, s2;
    s1.push(runner);
    while (!s1.empty())
    {
        runner = s1.top();
        s1.pop();
        s2.push(runner);
        if (runner->left)
            s1.push(runner->left);
        if (runner->right)
            s1.push(runner->right);
    }
    while (!s2.empty())
    {
        runner = s2.top();
        s2.pop();
        cout << runner->data << " ";
    }
}
int main()
{
    TreeNode *t = new TreeNode(10);
    t->left = new TreeNode(20);
    t->left->left = new TreeNode(50);
    t->left->right = new TreeNode(23);
    t->right = new TreeNode(60);
    t->right->left = new TreeNode(33);
    t->right->right = new TreeNode(89);
    preOrderTraversal(t);
    cout << endl;
    inOrderTraversal(t);
    cout << endl;
    postOrderTraversal(t);
    return 0;
}

// Preorder Traversal (Root, Left, Right): 10, 20, 50, 23, 60, 33, 89

// Inorder Traversal (Left, Root, Right): 50, 20, 23, 10, 33, 60, 89

// Postorder Traversal (Left, Right, Root): 50, 23, 20, 33, 89, 60, 10