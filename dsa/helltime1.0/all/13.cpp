class Solution
{
public:
    int romanToInt(std::string s)
    {
        std::unordered_map<char, int> numeralToValue{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int total = numeralToValue[s.back()];
        for (int i = 0; i < s.size() - 1; ++i)
        {
            int sign = numeralToValue[s[i]] < numeralToValue[s[i + 1]] ? -1 : 1;
            total += sign * numeralToValue[s[i]];
        }
        return total;
    }
};