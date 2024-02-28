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
    int findBottomLeftValue(TreeNode *root)
    {
        int bottom = 0;
        queue<TreeNode *> queue{{root}};
        while (!queue.empty())
        {
            bottom = queue.front()->val;
            for (int i = static_cast<int>(queue.size()); i > 0; --i)
            {
                TreeNode *current = queue.front();
                queue.pop();
                if (current->left)
                {
                    queue.push(current->left);
                }
                if (current->right)
                {
                    queue.push(current->right);
                }
            }
        }
        return bottom;
    }
};