class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return {};
        }
        vector<string> digitChars = {
            "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> combinations = {""};
        for (const auto digit : digits)
        {
            string chars = digitChars[digit - '2'];
            vector<string> tempCombinations;
            for (const auto comb : combinations)
            {
                for (const auto ch : chars)
                {
                    tempCombinations.emplace_back(comb + ch);
                }
            }
            combinations = move(tempCombinations);
        }
        return combinations;
    }
};