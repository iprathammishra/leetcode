class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        string str;
        int count = 0;
        if (s.find_last_not_of(' ') != string::npos)
        {
            str = s.substr(0, s.find_last_not_of(' ') + 1);
        }
        for (int i = str.length() - 1; i >= 0; i--)
        {
            if (str[i] == ' ')
            {
                break;
            }
            count++;
        }
        return count;
    }
};