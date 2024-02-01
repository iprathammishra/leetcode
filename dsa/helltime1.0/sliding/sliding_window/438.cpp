class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> rvec;
        vector<int> svec(26, 0);
        vector<int> pvec(26, 0);
        int window = p.length();
        int len = s.length();
        if (len < window)
            return rvec;
        int left = 0;
        int right = 0;
        while (right < window)
        {
            ++pvec[p[right] - 'a'];
            ++svec[s[right++] - 'a'];
        }
        --right;
        while (right < len)
        {
            if (pvec == svec)
                rvec.push_back(left);
            ++right;
            if (right != len)
                ++svec[s[right] - 'a'];
            --svec[s[left] - 'a'];
            ++left;
        }
        return rvec;
    }
};