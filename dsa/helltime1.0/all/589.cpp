/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        if (!root)
        {
            return {};
        }
        vector<int> ans;
        stack<Node *> s;
        s.push(root);
        while (!s.empty())
        {
            Node *current = s.top();
            s.pop();
            ans.emplace_back(current->val);
            for (int i = current->children.size() - 1; i >= 0; --i)
            {
                s.push(current->children[i]);
            }
        }
        return ans;
    }
};