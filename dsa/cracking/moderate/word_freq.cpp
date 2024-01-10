// 2. **Word Frequencies:** Design a method to find the frequency of occurrences of any given word in a book. What if we were running this algorithm multiple times?
#include <iostream>
#include <string>
#include <unordered_map>
std::unordered_map<char, int> countWordFrequency(const std::string& words)
{   
    std::unordered_map<char, int> wordFrequency;
    for (char i : words)
        ++wordFrequency[i];
    return wordFrequency;
}
int main()
{
    std::cout << countWordFrequency("Prathammmmmmmmm")['m'];
    return 0;
}

// Question: ++wordFrequencies[word]; why not use wordFrequencies[word]++;

// Answer: Both ++wordFrequencies[word] and wordFrequencies[word]++ increment the value associated with the key word in the wordFrequencies map. The difference lies in the return value.

// ++wordFrequencies[word] increments the value and returns the updated value. On the other hand, wordFrequencies[word]++ returns the current value and then increments it.

// In the context of counting word frequencies, where you just want to increment the count and don't need the old value, using ++wordFrequencies[word] is more efficient. It avoids the creation of a temporary copy of the old value.

// So, for this specific use case, ++wordFrequencies[word] is preferred for its simplicity and efficiency.