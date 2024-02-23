class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combinations;
        vector<int> comb_combo;
        function<void(int, int)> dfs = [&](int index, int remaining_sum) -> void
        {
            if (remaining_sum == 0)
            {
                combinations.push_back(comb_combo);
                return;
            }
            if (index >= candidates.size() || remaining_sum < candidates[index])
            {
                return;
            }
            for (int i = index; i < candidates.size(); i++)
            {
                if (i > index && candidates[i] == candidates[i - 1])
                {
                    continue;
                }
                comb_combo.push_back(candidates[i]);
                dfs(i + 1, remaining_sum - candidates[i]);
                comb_combo.pop_back();
            }
        };
        dfs(0, target);
        return combinations;
    }
};