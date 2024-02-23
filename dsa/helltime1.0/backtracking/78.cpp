class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> answer;
        vector<int> combination;
        function<void(int)> dfs = [&](int index) -> void
        {
            if (index == nums.size())
            {
                answer.push_back(combination);
                return;
            }
            dfs(index + 1);
            combination.push_back(nums[index]);
            dfs(index + 1);
            combination.pop_back();
        };
        dfs(0);
        return answer;
    }
};