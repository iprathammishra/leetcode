// 7. **Baby Names:** Each year, the government releases a list of the 10000 most common baby names and their frequencies (the number of babies with that name). The only problem with this is that some names have multiple spellings. For example, "John" and "Jon" are essentially the same name but would be listed separately in the list. Given two lists, one of names/frequencies and the other of pairs of equivalent names. Write an algorithm to print a new list of the true frequency of each name. Note that if John and Jon are synonyms, and Jon and Johnny are synonyms, then John and Johnny are synonyms. (It is both transitive and symmetric.) In the final list, any name can be used as the "real" name.

// Example:

// Input:
// Names: John (15), Jon (12), Chris (13), Kris (4), Christopher (19)
// Synonyms: (Jon, John), (John, Johnny), (Chris, Kris), (Christopher, Chris)
// Output: John (27), Kris (36)
#include <iostream>
#include <unordered_map>
std::unordered_map<std::string, int> babyNames(std::unordered_map<std::string, int> &names, std::unordered_map<std::string, std::string> &synonyms)
{
    std::unordered_map<std::string, int> fMap = {{"xc", -1}};
    for (std::pair<std::string, int> pair : names)
        if (synonyms.find(pair.first) != synonyms.end())
            if (names.find(synonyms.at(pair.first)) == names.end())
                synonyms.erase(pair.first);

    // for (std::pair<std::string, std::string> pair : synonyms)
    //     std::cout << pair.first << " " << pair.second << std::endl;
    return fMap;
}
int main()
{
    std::unordered_map<std::string, int> names = {
        {"John", 15},
        {"Jon", 12},
        {"Chris", 13},
        {"Kris", 4},
        {"Christopher", 19}};
    std::unordered_map<std::string, std::string> synonyms = {
        {"Jon", "John"},
        {"John", "Johnny"},
        {"Chris", "Kris"},
        {"Christopher", "Chris"}};
    std::unordered_map<std::string, int> fMap = babyNames(names, synonyms);
    for (std::pair<std::string, int> pair : fMap)
        std::cout << pair.first << " " << pair.second << std::endl;
    return 0;
}