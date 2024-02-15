class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> map;
        for (const string &word : words)
            map[word]++;
        vector<string> uniqueWords;
        for (const auto &[s, i] : map)
            uniqueWords.push_back(s);
        sort(uniqueWords.begin(), uniqueWords.end(), [&](string a, string b)
             {
            if (map[a] == map[b])
                return a < b;
            else
                return map[a] > map[b]; });
        vector<string> result(uniqueWords.begin(), uniqueWords.begin() + k);
        return result;
    }
};