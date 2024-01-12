// 18. **Pattern Matching:** You are given two strings, pattern and value. The pattern string consists of just the letters a and b, describing a pattern within a string. For example, the string catcatgocatgo matches the pattern aabab (where cat is a and go is b). It also matches patterns like a, ab and b. Write a method to determine if value matches pattern.
#include <iostream>
bool patternMatching(const std::string &value, const std::string &pattern)
{
    std::string result;
    int j = 0;
    if (pattern.length() > value.length())
        return false;
    for (int i = 0; i < value.length(); ++i)
    {
        if (pattern[j] == 'a')
        {
            result = value.substr(i, 3);
            i += 2;
            if (result[2] != 't')
                return false;
        }
        else if (pattern[j] == 'b')
        {
            result = value.substr(i, 2);
            i++;
            if (result[1] != 'o')
                return false;
        }
        j++;
    }
    return true;
}
int main()
{
    std::cout << patternMatching("catcatgo", "aab") << std::endl;
    return 0;
}