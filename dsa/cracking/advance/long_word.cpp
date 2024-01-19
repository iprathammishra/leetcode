// 15. **Longest Word:** Given a list of words, write a program to find the longest word made of other words in the list.

// Example:<br>
// Input: cat, banana, dog, nana, walk, walker, dogwalker <br>
// Output: dogwalker
#include <iostream>
#include <set>
#include <vector>

std::string longestWord(const std::vector<std::string> &inp)
{
    std::set<std::string> out;
    for (const std::string s : inp)
        for (int i = 0; i < inp.size(); ++i)
            if (inp[i].find(s) != std::string::npos && inp[i] != s)
                out.insert(inp[i]);
    int count = 0;
    std::string max_element;
    for (const std::string s : out)
        if (s.length() > count)
        {
            count = s.length();
            max_element = s;
        }

    return max_element;
}
int main()
{
    std::vector<std::string> inp = {"apple", "banana", "orange", "pear", "applepear", "orangeapple"};
    ;

    std::cout << longestWord(inp);
    return 0;
}