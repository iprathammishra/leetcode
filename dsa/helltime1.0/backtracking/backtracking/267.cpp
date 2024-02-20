class Solution
{
public:
    vector<string> all_plaindromes(string s)
    {
        vector<string> palindromes;
        string middle_element = "";
        unordered_map<char, int> map;
        for (const char &character : s)
        {
            map[character]++;
        }
        for (const auto &[character, frequency] : map)
        {
            if (frequency % 2 != 0)
            {
                if (middle_element == "")
                {
                    return palindromes;
                }
                middle_element = character;
            }
        }
        function<void(string)> dfs = [&](string &current_string) -> void
        {
            if (current_string.length() == s.length())
            {
                palindromes.push_back(current_string);
                return;
            }
            for (auto &[character, frequency] : map)
            {
                if (frequency > 1)
                {
                    frequency -= 2;
                    dfs(character + current_string + character);
                    frequency += 2;
                }
            }
        };
        dfs(middle_element);
        return palindromes;
    }
};
