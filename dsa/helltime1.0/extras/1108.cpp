class Solution
{
public:
    string defangIPaddr(string address)
    {
        string defang = "[.]";
        string res;
        for (const char &c : address)
        {
            if (c != '.')
            {
                res.push_back(c);
            }
            else
            {
                res.push_back('[');
                res.push_back('.');
                res.push_back(']');
            }
        }
        return res;
    }
};