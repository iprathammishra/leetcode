class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 > len2)
            return false;
        vector<int> charCount(26, 0);
        for (int i = 0; i < len1; i++)
        {
            charCount[s1[i] - 'a']--;
            charCount[s2[i] - 'a']++;
        }
        int diffCount = 0;
        for (const int &count : charCount)
            if (count != 0)
                diffCount++;
        if (diffCount == 0)
            return true;
        for (int i = len1; i < len2; i++)
        {
            int index1 = s2[i - len1] - 'a';
            int index2 = s2[i] - 'a';
            if (charCount[index2] == 0)
                diffCount++;
            charCount[index2]++;
            if (charCount[index2] == 0)
                diffCount--;
            if (charCount[index1] == 0)
                diffCount++;
            charCount[index1]--;
            if (charCount[index1] == 0)
                diffCount--;
            if (diffCount == 0)
                return true;
        }
        return false;
    }
};