class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        std::unordered_map<char, std::unordered_set<std::string>> wordMap;
        for (const auto &w : ideas)
        {
            wordMap[w[0]].insert(w.substr(1));
        }

        long long res = 0;
        for (const auto &[char1, set1] : wordMap)
        {
            for (const auto &[char2, set2] : wordMap)
            {
                if (char1 == char2)
                    continue;

                int intersect = 0;
                for (const auto &w : set1)
                {
                    if (set2.find(w) != set2.end())
                        intersect++;
                }

                int distinct1 = set1.size() - intersect;
                int distinct2 = set2.size() - intersect;
                res += distinct1 * distinct2;
            }
        }

        return res;
    }
};