class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> fmap;
        for (const int &i : nums)
            fmap[i]++;
        vector<int> uniqueCharacters;
        for (const auto &[i, j] : fmap)
            uniqueCharacters.push_back(i);
        sort(uniqueCharacters.begin(), uniqueCharacters.end(), [&](int a, int b)
             { return fmap[a] > fmap[b]; });
        uniqueCharacters.erase(uniqueCharacters.begin() + k, uniqueCharacters.end());
        return uniqueCharacters;
    }
};