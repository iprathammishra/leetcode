class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int oneCount = count_if(s.begin(), s.end(), [](char c)
                                { return c == '1'; });
        string answer;
        for (int i = 1; i < oneCount; i++)
        {
            answer.push_back('1');
        }
        for (int i = 0; i < s.size() - oneCount; i++)
        {
            answer.push_back('0');
        }
        answer.push_back('1');
        return answer;
    }
};