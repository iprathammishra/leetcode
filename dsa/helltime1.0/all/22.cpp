class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> combinations;
        function<void(int, int, string)> backtrack = [&](int open, int close, string path) -> void
        {
            if (open > n || close > n || open < close)
            {
                return;
            }
            if (open == n && close == n)
            {
                combinations.emplace_back(path);
                return;
            }
            backtrack(open + 1, close, path + '(');
            backtrack(open, close + 1, path + ')');
        };
        backtrack(0, 0, "");
        return combinations;
    }
};