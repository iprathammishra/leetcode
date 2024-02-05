class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        map<int, int> nmap;
        for (const int &i : nums)
            nmap[i]++;
        for (const auto &i : nmap)
            if (i.second == 1)
                return i.first;
        return nums[0];
    }
};