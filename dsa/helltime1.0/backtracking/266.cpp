class Solution
{
    bool canPermutePalindrome(string s)
    {
        int[] charCount = new int[26];
        for (char character : s)
        {
            charCount[character - 'a']++;
        }
        int oddCount = 0;
        for (int count : charCount)
        {
            oddCount += count % 2;
        }
        return oddCount < 2;
    }
};