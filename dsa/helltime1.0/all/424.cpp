class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> charcount(26, 0);
        int left = 0;
        int right = 0;
        int maxcount = 0;
        for (right = 0; right < s.length(); right++)
        {
            charcount[s[right] - 'A']++;
            maxcount = max(maxcount, charcount[s[right] - 'A']);
            if (right - left + 1 - maxcount > k)
            {
                charcount[s[left] - 'A']--;
                left++;
            }
        }
        return right - left;
    }
};