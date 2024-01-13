// 20. **T9:** On old cell phones, users typed on a numeric keypad and the phone would provide a list of words that matched these numbers. Each digit mapped to a set of 0-4 letters. Implement an algorithm to return a list of matching words, given a sequence of digits. You are provided a list of valid words (provided in whatever data structure you'd like). The mapping is shown in the diagram below:

// [Image](/leetcode/assets/mod20.png)

// Example:

// Input: 8733
// Output: tree, used
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
std::unordered_map<int, std::string> cellMap = {
    {2, "abc"},
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"},
};
std::vector<std::string> listOfMatchingWords(std::vector<std::string> &words, const int &num)
{
    std::vector<std::string> tempVector;
    std::string key = std::to_string(num);
    for (int i = 0; i < key.length(); ++i)
    {
        for (int j = 0; j < words.size(); ++j)
            if (words[j][i] == cellMap.at(key[i] - '0')[i])
                tempVector.push_back(words[j]);
            else if (words[j][i] == cellMap.at(key[i] - '0')[i + 1])
                tempVector.push_back(words[j]);
            else if (words[j][i] == cellMap.at(key[i] - '0')[i + 2])
                tempVector.push_back(words[j]);
            else if (words[j][i] == cellMap.at(key[i] - '0')[i + 3])
                tempVector.push_back(words[j]);
        if (tempVector.size() > 0)
        {
            words.swap(tempVector);
            tempVector.clear();
        }
        // for (std::string s : words)
        //     std::cout << s << " ";
        // std::cout << std::endl;
    }
    std::cout << std::endl;
    return words;
}
int main()
{
    std::vector<std::string> w, result;
    w = {"tree", "used", "hello", "world", "effect", "effect"};
    result = listOfMatchingWords(w, 333328);
    for (std::string i : result)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
