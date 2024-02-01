class Solution
{
public:
    int lengthOfLongestSubstring(string text)
    {
        set<char> cset;
        int size = 0;
        int left = 0;
        for (int right = 0; right < text.length(); ++right)
        {
            while (cset.count(text[right]))
            {
                cset.erase(text[left]);
                ++left;
            }
            cset.insert(text[right]);
            size = max(size, right - left + 1);
        }
        return size;
    }
};