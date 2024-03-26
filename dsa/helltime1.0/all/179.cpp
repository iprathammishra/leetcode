class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> cmp;
        for (const auto it : nums)
        {
            cmp.emplace_back(to_string(it));
        }
        sort(cmp.begin(), cmp.end(), [](string a, string b)
             { return a + b > b + a; });
        if (cmp[0] == "0")
        {
            return "0";
        }
        string result;
        for (const auto it : cmp)
        {
            result += it;
        }
        return result;
    }
};