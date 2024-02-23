class Solution
{
private:
    bool is_palindrome(string &str, int left, int right)
    {
        while (left < right)
        {
            if (str[left] != str[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> part;
        function<void(int)> dfs = [&](int index) -> void
        {
            if (index >= s.length())
            {
                res.emplace_back(part);
                return;
            }
            for (int i = index; i < s.length(); i++)
            {
                if (is_palindrome(s, index, i))
                {
                    part.push_back(s.substr(index, i - index + 1));
                    dfs(i + 1);
                    part.pop_back();
                }
            }
        };
        dfs(0);
        return res;
    }
};