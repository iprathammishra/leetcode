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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;
        queue<TreeNode *> queueNodes;
        queueNodes.push(root);
        bool isLeftToRight = true;
        while (!queueNodes.empty())
        {
            int levelSize = queueNodes.size();
            vector<int> level;
            while (levelSize > 0)
            {
                TreeNode *current = queueNodes.front();
                queueNodes.pop();
                level.push_back(current->val);
                if (current->left)
                    queueNodes.push(current->left);
                if (current->right)
                    queueNodes.push(current->right);
                levelSize--;
            }
            if (!isLeftToRight)
                reverse(level.begin(), level.end());
            result.push_back(level);
            isLeftToRight = !isLeftToRight;
        }
        return result;
    }
};