class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        vector<int> combination;
        function<void(int)> dfs = [&](int index) -> void
        {
            answer.push_back(combination);
            for (int i = index; i < nums.size(); i++)
            {
                if (i != index && nums[i] == nums[i - 1])
                {
                    continue;
                }
                combination.push_back(nums[i]);
                dfs(i + 1);
                combination.pop_back();
            }
        };
        dfs(0);
        return answer;
    }
};