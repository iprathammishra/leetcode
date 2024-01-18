// 13. **Re-space:** Oh, no! You have accidentally removed all spaces, punctuation, and capitalization in a lengthy document. A sentence like "I reset the computer. It still didn't boot!" became "iresetthecomputeritstilldidntboot". You'll deal with the punctuation and capitalization later; right now you need to re-insert the spaces. Most of the words are in a dictionary but a few are not. Given a dictionary (a list of strings) and the document (a string), design an algorithm to unconcatenate the document in a way that minimizes the number of unrecognized characters.

// Example:
// Input: jesslookedjustliketimherbrother
// Output: (jess) looked just like (tim) her brother (7 unrecognized characters)
#include <iostream>
#include <vector>
#include <sstream>
std::pair<std::string, int> re_space(const std::string &text, std::vector<std::string> &dict)
{
    std::string str = text;
    std::string str2 = "";
    std::string str3 = text;
    int unrecognizedCharacters;
    for (const std::string s : dict)
        if (str3.find(s))
            str3.erase(str3.find(s), s.length());
    unrecognizedCharacters = str3.length();
    for (const std::string s : dict)
        if (str.find(s))
            str.replace(str.find(s), s.length(), "0");
    str = "0" + str;
    for (int i = 1; i < str.length(); ++i)
        if (isalpha(str[i]) && isdigit(str[i - 1]))
        {
            std::stringstream ss;
            ss << str[i];
            str.replace(i, 1, "(" + ss.str());
        }
        else if (isalpha(str[i]) && isdigit(str[i + 1]))
        {
            std::stringstream ss;
            ss << str[i];
            str.replace(i, 1, ss.str() + ")");
        }
    str.erase(0, 1);
    for (int i = 0; i < str.length(); ++i)
        if (str[i] == '0')
        {
            str.replace(i, 1, dict[0] + " ");
            dict.erase(dict.begin());
        }
        else if (str[i] == ')')
            str.replace(i, 1, ") ");
    return {str, unrecognizedCharacters};
}
int main()
{
    std::string text = "jesslookedjustliketimherbrother";
    std::vector<std::string> dictionary = {"looked", "just", "like", "her", "brother"};
    std::pair<std::string, int> pair = re_space(text, dictionary);
    std::cout << "Text: " << pair.first << " UC: " << pair.second;
    return 0;
}