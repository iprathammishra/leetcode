// A `Binary Search Tree (BST)` is a collection of nodes arranged in a way where they maintain BST properties.

// - Every node in the `left subtree` has a value `less` than the value of its parent node.
// - Every node in the `right subtree` has a value `greater than or equal to` the value of its parent node.
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
class BinarySearchTree
{
private:
    TreeNode *root;

public:
    BinarySearchTree() : root(nullptr) {}
    void insert(int value)
    {
        TreeNode *newNode = new TreeNode(value);
        if (!root)
        {
            root = newNode;
            return;
        }
        TreeNode *current = root;
        while (true)
        {
            if (value < current->data)
            {
                if (!current->left)
                {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            }
            else
            {
                if (!current->right)
                {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            }
        }
    }
    bool search(int value)
    {
        TreeNode *current = root;
        while (current)
            if (value == current->data)
                return true;
            else if (value < current->data)
                current = current->left;
            else
                current = current->right;
        return false;
    }
    void deleteNode(int value)
    {
        TreeNode *parent = nullptr;
        TreeNode *current = root;
        while (current && current->data != value)
        {
            parent = current;
            if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }
        if (!current)
            return;
        if (!current->left)
        {
            if (!parent)
                root = current->right;
            else if (parent->left == current)
                parent->left = current->right;
            else
                parent->right = current->right;
            delete current;
        }
        else if (!current->right)
        {
            if (!parent)
                root = current->left;
            else if (parent->left == current)
                parent->left = current->left;
            else
                parent->right = current->left;
            delete current;
        }
        else
        {
            TreeNode *successor = current->right;
            parent = current;
            while (!successor->left)
            {
                parent = successor;
                successor = successor->left;
            }
            current->data = successor->data;
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
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *current = s.top();
            s.pop();
            cout << current->data << ">> ";
            if (current->right)
                s.push(current->right);
            if (current->left)
                s.push(current->left);
        }
        cout << endl;
    }
    void inOrderTraversal()
    {
        if (!root)
            return;
        stack<TreeNode *> s;
        TreeNode *current = root;
        while (current || !s.empty())
        {
            while (current)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            cout << current->data << ">> ";
            current = current->right;
        }
        cout << endl;
    }
    void postOrderTraversal()
    {
        if (!root)
            return;
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            TreeNode *current = s1.top();
            s1.pop();
            s2.push(current);
            if (current->left)
                s1.push(current->left);
            if (current->right)
                s1.push(current->right);
        }
        while (!s2.empty())
        {
            TreeNode *current = s2.top();
            s2.pop();
            cout << current->data << ">> ";
        }
        cout << endl;
    }
};
int main()
{
    int choice, val;
    BinarySearchTree bst;
    bool running = true;
    while (running)
    {
        cout << "Enter you choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value you want to insert: ";
            cin >> val;
            bst.insert(val);
            break;
        case 2:
            cout << "Enter the value you want to search: ";
            cin >> val;
            (bst.search(val)) ? cout << "Found" << endl : cout << "Not Found" << endl;
            break;
        case 3:
            cout << "Enter the value you want to delete: ";
            cin >> val;
            bst.deleteNode(val);
            break;
        case 4:
            cout << "InOrderTraversal: " << endl;
            bst.inOrderTraversal();
            break;
        case 5:
            cout << "PreOrderTraversal: " << endl;
            bst.preOrderTraversal();
            break;
        case 6:
            cout << "PostOrderTraversal: " << endl;
            bst.postOrderTraversal();
            break;
        case 0:
            running = false;
            break;
        default:
            cout << "Invalid Response!" << endl;
            break;
        }
    }
    return 0;
}
