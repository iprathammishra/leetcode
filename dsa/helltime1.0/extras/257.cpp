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
private:
    string join(const vector<string> &tokens, const string &separator = "->")
    {
        string path;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (i > 0)
                path += separator;
            path += tokens[i];
        }
        return path;
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> path;
        vector<string> currentNodes;
        function<void(TreeNode *)> dfs = [&](TreeNode *node)
        {
            if (!node)
                return;
            currentNodes.push_back(to_string(node->val));
            if (!node->left && !node->right)
                path.push_back(join(currentNodes));
            else
            {
                dfs(node->left);
                dfs(node->right);
            }
            currentNodes.pop_back();
        };
        dfs(root);
        return path;
    }
};