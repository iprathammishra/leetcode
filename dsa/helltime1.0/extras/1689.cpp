class Solution
{
public:
    int minPartitions(string n)
    {
        int mx = n[0] - '0';
        for (const char &c : n)
        {
            mx = max(mx, c - '0');
        }
        return mx;
    }
};