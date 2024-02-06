class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> gmap;
        vector<vector<string>> result;
        for (const string &str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            gmap[key].push_back(str);
        }
        for (const auto &i : gmap)
            result.push_back(i.second);
        return result;
    }
};