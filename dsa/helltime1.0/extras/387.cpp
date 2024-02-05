class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> smap;
        for (const char &c : s)
            ++smap[c];
        for (const char &c : s)
            if (smap[c] == 1)
                return s.find(c);
        return -1;
    }
};