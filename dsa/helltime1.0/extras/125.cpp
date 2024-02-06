class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str;
        for (const char &c : s)
            if (isalnum(c))
                str.push_back(tolower(c));
        int start = 0;
        int end = str.size() - 1;
        while (start < end)
        {
            if (str[start] != str[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};