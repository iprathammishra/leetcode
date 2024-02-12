class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> nmap;
        for (const int &i : nums)
            nmap[i]++;
        vector<int> univec;
        for (const auto &[i, j] : nmap)
            univec.push_back(i);
        sort(univec.begin(), univec.end(), [&](int a, int b)
             { return nmap[a] < nmap[b]; });
        return univec.back();
    }
};