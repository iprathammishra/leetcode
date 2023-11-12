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
class BST
{
private:
    TreeNode *root;

public:
    BST() : root(nullptr) {}
    void insertTreeNode(int value)
    {
        TreeNode *newNode = new TreeNode(value);
        if (!root)
        {
            root = newNode;
            return;
        }
        TreeNode *runner = root;
        while (true)
            if (value < runner->data)
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
    bool searchTreeNode(int value)
    {
        if (!root)
            return false;
        TreeNode *runner = root;
        while (runner && runner->data != value)
            if (value < runner->data)
                runner = runner->left;
            else
                runner = runner->right;
        return (!runner) ? false : true;
    }
    void deleteTreeNode(int value)
    {
        if (!root)
            return;
        TreeNode *runner = root;
        TreeNode *parent = nullptr;
        while (runner && runner->data != value)
        {
            parent = runner;
            if (value < runner->data)
                runner = runner->left;
            else
                runner = runner->right;
        }
        if (!runner)
            return;
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
    }
    void preOrderTraversal()
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
    void inOrderTraversal()
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
    void postOrderTraversal()
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
};
int main()
{
    int choice, val;
    bool running = true;
    BST bst;
    while (running)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            running = false;
            break;
        case 1:
            cout << "Enter the value: ";
            cin >> val;
            bst.insertTreeNode(val);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> val;
            bst.deleteTreeNode(val);
            break;
        case 3:
            cout << "Enter the value: ";
            cin >> val;
            (bst.searchTreeNode(val)) ? cout << "Found." : cout << "Not Found.";
            break;
        case 4:
            cout << "PreOrder: ";
            bst.preOrderTraversal();
            cout << endl;
            break;
        case 5:
            cout << "InOrder: ";
            bst.inOrderTraversal();
            cout << endl;
            break;
        case 6:
            cout << "PostOrder: ";
            bst.postOrderTraversal();
            cout << endl;
            break;
        default:
            cout << "Invalid response.";
            cout << endl;
            break;
        }
    }
    return 0;
}