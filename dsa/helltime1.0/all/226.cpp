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
    TreeNode *invertTree(TreeNode *root)
    {
        function<void(TreeNode *)> rec = [&](TreeNode *node) -> void
        {
            if (!node)
            {
                return;
            }
            swap(node->left, node->right);
            rec(node->left);
            rec(node->right);
        };
        rec(root);
        return root;
    }
};