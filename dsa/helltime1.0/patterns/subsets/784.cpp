class Solution
{
public:
    vector<string> letterCasePermutation(string s)
    {
        vector<string> permutations;
        function<void(int)> dfs = [&](int index) -> void
        {
            if (index >= s.size())
            {
                permutations.push_back(s);
                return;
            }
            dfs(index + 1);
            if (isalpha(s[index]))
            {
                s[index] ^= 32;
                dfs(index + 1);
            }
        };
        dfs(0);
        return permutations;
    }
};