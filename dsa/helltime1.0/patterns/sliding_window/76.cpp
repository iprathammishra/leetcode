// The problem you're experiencing is due to the fact that your current solution doesn't guarantee the smallest substring that contains all the characters in t. It only finds a substring that contains all the characters, but not necessarily the smallest one.

// The issue lies in the inner while loop. Once uniqueNow == unique, you start to move the left pointer to the right. However, you should only move the left pointer when the current character at s[left] is not a character in t or when the frequency of s[left] in freqs is greater than that in freqt.

// Here's the corrected code:

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.length() < t.length())
            return "";
        unordered_map<char, int> freqt;
        unordered_map<char, int> freqs;
        for (const char c : t)
            ++freqt[c];
        int left = 0;
        int right = 0;
        int size = INT_MAX;
        int st = 0;
        int length = s.length();
        int unique = freqt.size();
        int uniqueNow = 0;
        while (right < length)
        {
            char rchar = s[right];
            if (freqt.count(rchar))
            {
                freqs[rchar]++;
                if (freqs[rchar] == freqt[rchar])
                    uniqueNow++;
            }
            while (left <= right && uniqueNow == unique)
            {
                char lchar = s[left];
                if (right - left + 1 < size)
                {
                    st = left;
                    size = right - left + 1;
                }
                if (freqt.count(lchar))
                {
                    if (freqs[lchar] == freqt[lchar])
                        uniqueNow--;
                    freqs[lchar]--;
                }
                left++;
            }
            right++;
        }
        return size == INT_MAX ? "" : s.substr(st, size);
    }
};

// In this corrected code, I've added checks to see if s[left] and s[right] are in t before updating freqs and uniqueNow. This ensures that we only consider characters in t when moving the left and right pointers.
