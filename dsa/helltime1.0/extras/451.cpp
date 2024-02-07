class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> smap;
        for (const char &c : s)
            smap[c]++;
        vector<char> uvec;
        for (const auto &[c, i] : smap)
            uvec.push_back(c);
        sort(uvec.begin(), uvec.end(), [&](char a, char b)
             { return smap[a] > smap[b]; });
        string res;
        for (const char &c : uvec)
            res += string(smap[c], c);
        return res;
    }
};