class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combinations;
        vector<int> comb_combo;
        function<void(int, int)> dfs = [&](int start_index, int remaining_sum) -> void
        {
            if (remaining_sum == 0)
            {
                combinations.push_back(comb_combo);
                return;
            }
            if (start_index >= candidates.size() || remaining_sum < candidates[start_index])
            {
                return;
            }
            dfs(start_index + 1, remaining_sum);
            comb_combo.push_back(candidates[start_index]);
            dfs(start_index, remaining_sum - candidates[start_index]);
            comb_combo.pop_back();
        };
        dfs(0, target);
        return combinations;
    }
};