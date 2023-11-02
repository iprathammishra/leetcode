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
int main()
{
    TreeNode *t = new TreeNode(10);
    t->left = new TreeNode(20);
    t->left->left = new TreeNode(50);
    t->left->right = new TreeNode(23);
    t->right = new TreeNode(60);
    t->right->left = new TreeNode(33);
    t->right->right = new TreeNode(89);
    inOrderTraversal(t);
    return 0;
}
