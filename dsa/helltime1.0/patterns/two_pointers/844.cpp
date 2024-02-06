class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        return processString(s) == processString(t);
    }

private:
    string processString(string str)
    {
        string result;
        for (const char &c : str)
            if (c != '#')
                result.push_back(c);
            else if (!result.empty())
                result.pop_back();
        return result;
    }
};