class Solution
{
public:
    int minimizedStringLength(string s)
    {
        set<char> res;
        for (const char &c : s)
            res.insert(c);
        return res.size();
    }
};