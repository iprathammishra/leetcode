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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        function<TreeNode *(int, int)> rec = [&](int left, int right) -> TreeNode *
        {
            if (left > right)
            {
                return nullptr;
            }
            int mid = left + (right - left) / 2;
            auto leftTree = rec(left, mid - 1);
            auto rightTree = rec(mid + 1, right);
            return new TreeNode(nums[mid], leftTree, rightTree);
        };
        return rec(0, nums.size() - 1);
    }
};