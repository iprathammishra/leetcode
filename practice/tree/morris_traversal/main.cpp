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
    void reverseNodes(TreeNode *from, TreeNode *to)
    {
        if (from == to)
            return;
        TreeNode *x = from;
        TreeNode *y = from->right;
        TreeNode *z;
        while (x != to)
        {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
        }
    }
    void printReverse(TreeNode *from, TreeNode *to)
    {
        reverseNodes(from, to);
        TreeNode *p = to;
        while (true)
        {
            cout << p->data << " ";
            if (p == from)
                break;
            p = p->right;
        }
        reverseNodes(to, from);
    }

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
        {
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
    }
    bool searchTreeNode(int value)
    {
        if (!root)
            return false;
        TreeNode *runner = root;
        while (runner && runner->data == value)
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
        while (runner && runner->data == value)
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
            while (!successor->left)
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
    void preOrderMorrisTraversal()
    {
        TreeNode *runner = root;
        while (runner)
            if (!runner->left)
            {
                cout << runner->data << " ";
                runner = runner->right;
            }
            else
            {
                TreeNode *predecessor = runner->left;
                while (predecessor->right && predecessor->right != runner)
                    predecessor = predecessor->right;
                if (!predecessor->right)
                {
                    cout << runner->data << " ";
                    predecessor->right = runner;
                    runner = runner->left;
                }
                else
                {
                    predecessor->right = nullptr;
                    runner = runner->right;
                }
            }
    }
    void inOrderMorrisTraversal()
    {
        TreeNode *runner = root;
        while (runner)
            if (!runner->left)
            {
                cout << runner->data << " ";
                runner = runner->right;
            }
            else
            {
                TreeNode *predecessor = runner->left;
                while (predecessor->right && predecessor->right != runner)
                    predecessor = predecessor->right;
                if (!predecessor->right)
                {
                    predecessor->right = runner;
                    runner = runner->left;
                }
                else
                {
                    predecessor->right = nullptr;
                    cout << runner->data << " ";
                    runner = runner->right;
                }
            }
    }
    void postOrderMorrisTraversal()
    {
        TreeNode dummy(0);
        dummy.left = root;
        TreeNode *runner = &dummy;
        while (runner)
            if (!runner->left)
                runner = runner->right;
            else
            {
                TreeNode *predecessor = runner->left;
                while (predecessor->right && predecessor->right != runner)
                    predecessor = predecessor->right;
                if (!predecessor->right)
                {
                    predecessor->right = runner;
                    runner = runner->left;
                }
                else
                {
                    printReverse(runner->left, predecessor);
                    predecessor->right = nullptr;
                    runner = runner->right;
                }
            }
    }
    void preOrderIterativeTraversal() {}
    void inOrderIterativeTraversal() {}
    void postOrderIterativeTraversal() {}
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
            cout << "Enter the value you want to insert: ";
            cin >> val;
            bst.insertTreeNode(val);
            break;
        case 2:
            cout << "Enter the value you want to delete: ";
            cin >> val;
            bst.deleteTreeNode(val);
            break;
        case 3:
            cout << "Enter the value you want to search: ";
            cin >> val;
            bst.searchTreeNode(val);
            break;
        case 4:
            cout << "PreOrderMorris: \n";
            bst.preOrderMorrisTraversal();
            cout << "\n";
            break;
        case 5:
            cout << "InOrderMorris: \n";
            bst.inOrderMorrisTraversal();
            cout << "\n";
            break;
        case 6:
            cout << "PostOrderMorris: \n";
            bst.postOrderMorrisTraversal();
            cout << "\n";
            break;
        case 7:
            cout << "PreOrderIterative: \n";
            bst.preOrderMorrisTraversal();
            cout << "\n";
            break;
        case 8:
            cout << "InOrderIterative: \n";
            bst.inOrderMorrisTraversal();
            cout << "\n";
            break;
        case 9:
            cout << "PostOrderIterative: \n";
            bst.postOrderMorrisTraversal();
            cout << "\n";
            break;
        default:
            cout << "Invalid response.\n";
            break;
        }
    }
    return 0;
}