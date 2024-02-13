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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        stack<TreeNode *> s;
        TreeNode *runner = root;
        while (runner || !s.empty())
        {
            while (runner)
            {
                s.push(runner);
                runner = runner->left;
            }
            runner = s.top();
            s.pop();
            result.push_back(runner->val);
            runner = runner->right;
        }
        return result;
    }
};