class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> answer;
        vector<int> combination(nums.size());
        vector<bool> visited(nums.size(), false);
        function<void(int)> dfs = [&](int index) -> void
        {
            if (index == nums.size())
            {
                answer.push_back(combination);
                return;
            }
            for (int i = 0; i < nums.size(); i++)
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    combination[index] = nums[i];
                    dfs(index + 1);
                    visited[i] = false;
                }
            }
        };
        dfs(0);
        return answer;
    }
};