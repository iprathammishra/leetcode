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
    bool isEvenOddTree(TreeNode *root)
    {
        bool is_even_level = true;
        queue<TreeNode *> queue{{root}};
        while (!queue.empty())
        {
            int previous_value = is_even_level ? 0 : INT_MAX;
            for (int i = queue.size(); i > 0; i--)
            {
                root = queue.front();
                queue.pop();
                if (is_even_level && (root->val % 2 == 0 || previous_value >= root->val))
                {
                    return false;
                }
                if (!is_even_level && (root->val % 2 == 1 || previous_value <= root->val))
                {
                    return false;
                }
                previous_value = root->val;
                if (root->left)
                {
                    queue.push(root->left);
                }
                if (root->right)
                {
                    queue.push(root->right);
                }
            }
            is_even_level = !is_even_level;
        }
        return true;
    }
};