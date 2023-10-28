// **String Compression:** Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase letters (a-z).
#include <iostream>
#include <string>
using namespace std;
string compressString(const string &str)
{
    string cStr = "";
    char temp = str[0];
    int counter = 0;
    int i;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == temp)
            counter++;
        else
        {
            cStr = cStr + str[i - 1] + to_string(counter);
            counter = 1;
            temp = str[i];
        }
    }
    cStr = cStr + str[i - 1] + to_string(counter);
    return (str.length() > cStr.length()) ? cStr : str;
}
int main()
{
    cout << compressString("prattttthgggadddddm");
    return 0;
}
