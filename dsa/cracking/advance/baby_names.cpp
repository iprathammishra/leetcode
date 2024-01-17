// 7. **Baby Names:** Each year, the government releases a list of the 10000 most common baby names and their frequencies (the number of babies with that name). The only problem with this is that some names have multiple spellings. For example, "John" and "Jon" are essentially the same name but would be listed separately in the list. Given two lists, one of names/frequencies and the other of pairs of equivalent names. Write an algorithm to print a new list of the true frequency of each name. Note that if John and Jon are synonyms, and Jon and Johnny are synonyms, then John and Johnny are synonyms. (It is both transitive and symmetric.) In the final list, any name can be used as the "real" name.

// Example:

// Input:
// Names: John (15), Jon (12), Chris (13), Kris (4), Christopher (19)
// Synonyms: (Jon, John), (John, Johnny), (Chris, Kris), (Christopher, Chris)
// Output: John (27), Kris (36)
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

std::string findRepresentative(const std::unordered_map<std::string, std::string> &synonyms, const std::string &name)
{
    if (synonyms.find(name) == synonyms.end())
        return name;
    return findRepresentative(synonyms, synonyms.at(name));
}
std::unordered_map<std::string, int> calculateTrueFrequencies(const std::unordered_map<std::string, int> &names, const std::unordered_map<std::string, std::string> &synonyms)
{
    std::unordered_map<std::string, int> trueFrequencies;
    for (const auto &nameFreq : names)
    {
        std::string representative = findRepresentative(synonyms, nameFreq.first);
        trueFrequencies[representative] += nameFreq.second;
    }
    return trueFrequencies;
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

    std::unordered_map<std::string, int> trueFrequencies = calculateTrueFrequencies(names, synonyms);

    for (const auto &trueFreq : trueFrequencies)
    {
        std::cout << trueFreq.first << " (" << trueFreq.second << "), ";
    }

    return 0;
}
