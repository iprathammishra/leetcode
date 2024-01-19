// 17. **Multi Search:** Given a string b and an array of smaller strings T, design a method to search b for each small string in T.
#include <iostream>
#include <vector>
std::vector<std::pair<int, std::string>> multiSearch(const std::string &larger_string, const std::vector<std::string> &smaller_string)
{
    std::vector<std::pair<int, std::string>> out;
    for (const std::string s : smaller_string)
        if (larger_string.find(s) != std::string::npos)
            out.push_back({larger_string.find(s), s});
    return out;
}
int main()
{
    std::string larger_string = "ababcababcabc";
    std::vector<std::string> smaller_strings = {"ab", "abc", "bc", "a", "c", "abab"};
    std::vector<std::pair<int, std::string>> out = multiSearch(larger_string, smaller_strings);
    for (const auto &i : out)
        std::cout << "(" << i.first << ", " << i.second << ") ";
    return 0;
}