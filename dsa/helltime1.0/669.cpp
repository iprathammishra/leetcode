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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        function<TreeNode *(TreeNode *)> dfs = [&](TreeNode *node) -> TreeNode *
        {
            if (!node)
            {
                return nullptr;
            }
            if (node->val > high)
            {
                return dfs(node->left);
            }
            if (node->val < low)
            {
                return dfs(node->right);
            }
            node->left = dfs(node->left);
            node->right = dfs(node->right);
            return node;
        };
        return dfs(root);
    }
};