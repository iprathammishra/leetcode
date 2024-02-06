class Solution
{
public:
    string removeStars(string s)
    {
        string result;
        for (const char &c : s)
            if (c != '*')
                result.push_back(c);
            else if (!result.empty())
                result.pop_back();
        return result;
    }
};