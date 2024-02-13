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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;
        queue<TreeNode *> queueNodes;
        queueNodes.push(root);
        while (!queueNodes.empty())
        {
            int levelSize = queueNodes.size();
            vector<int> level;
            while (levelSize > 0)
            {
                TreeNode *lev = queueNodes.front();
                queueNodes.pop();
                level.push_back(lev->val);
                if (lev->left)
                    queueNodes.push(lev->left);
                if (lev->right)
                    queueNodes.push(lev->right);
                levelSize--;
            }
            result.push_back(level);
        }
        return result;
    }
};