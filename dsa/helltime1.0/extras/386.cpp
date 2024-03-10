class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<string> v;
        vector<int> v1;
        for (int i = 1; i < n + 1; i++)
        {
            v.push_back(to_string(i));
        }
        sort(v.begin(), v.end());
        for (const string it : v)
        {
            v1.push_back(stoi(it));
        }
        return v1;
    }
};