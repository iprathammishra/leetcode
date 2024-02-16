class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> map;
        for (const int &value : arr)
        {
            map[value]++;
        }
        vector<pair<int, int>> freq(map.begin(), map.end());
        sort(freq.begin(), freq.end(), [&](pair<int, int> a, pair<int, int> b)
             { return a.second < b.second; });
        for (auto &[num, count] : freq)
        {
            if (k >= count)
            {
                k -= count;
                count = 0;
            }
            else
            {
                count -= k;
                k = 0;
            }
            if (k == 0)
            {
                break;
            }
        }
        int unique = 0;
        for (const auto &[num, count] : freq)
        {
            if (count > 0)
            {
                unique++;
            }
        }
        return unique;
    }
};