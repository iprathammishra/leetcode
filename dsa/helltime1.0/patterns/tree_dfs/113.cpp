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
    int nodeSum(const vector<int> &values)
    {
        int sum = 0;
        for (const int &value : values)
            sum += value;
        return sum;
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> path;
        vector<int> currentPath;
        function<void(TreeNode *)> dfs = [&](TreeNode *node)
        {
            if (!node)
                return;
            currentPath.push_back(node->val);
            if (!node->left && !node->right)
            {
                if (nodeSum(currentPath) == targetSum)
                    path.push_back(currentPath);
            }
            else
            {
                dfs(node->left);
                dfs(node->right);
            }
            currentPath.pop_back();
        };
        dfs(root);
        return path;
    }
};