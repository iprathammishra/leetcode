class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> smap, tmap;
        for (const char &c : s)
            smap[c]++;
        for (const char &c : t)
            tmap[c]++;
        return smap == tmap;
    }
};