class Solution
{
public:
    string removeDuplicates(string s)
    {
        string result;
        for (const char &c : s)
            if (!result.empty() && c == result.back())
                result.pop_back();
            else
                result.push_back(c);
        return result;
    }
};