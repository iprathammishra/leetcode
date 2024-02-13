/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        stack<TreeNode *> s;
        TreeerNode *runner = root;
        s.push(runner);
        while (!s.empty())
        {
            runner = s.top();
            s.pop();
            result.push_back(runner->val);
            if (runner->right)
                s.push(runner->right);
            if (runner->left)
                s.push(runner->left);
        }
        return result;
    }
};