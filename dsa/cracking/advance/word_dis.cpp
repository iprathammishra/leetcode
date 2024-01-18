// 11. **Word Distance:** You have large text file containing words. Given any two words, find the shortest distance (in terms of number of words) between them in the file. If the operation will be repeated many times for the same file (but different paris of words), can you optimize your solution?
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <climits>
class WordDistanceFinder
{
private:
    std::unordered_map<std::string, std::vector<int>> wordIndices;

public:
    WordDistanceFinder(const std::string &text)
    {
        std::istringstream iss(text);
        std::string word;
        int index = 0;
        while (iss >> word)
            wordIndices[word].push_back(++index);
    }
    int findShortestDistance(const std::string &word1, const std::string &word2)
    {
        const std::vector<int> &indices1 = wordIndices[word1];
        const std::vector<int> &indices2 = wordIndices[word2];
        int minDistance = INT_MAX;
        for (int i = 0, j = 0; i < indices1.size() && j < indices2.size();)
        {
            minDistance = std::min(minDistance, abs(indices1[i] - indices2[j]));

            if (indices1[i] < indices2[j])
                ++i;
            else
                ++j;
        }
        return minDistance;
    }
};
int main()
{
    std::string text = "This is a sample text. We are testing word distance in this text.";
    WordDistanceFinder distanceFinder(text);
    int shortestDistance = distanceFinder.findShortestDistance("sample", "We");

    std::cout << "Shortest distance: " << shortestDistance << std::endl;
    return 0;
}

// https://chat.openai.com/share/29a7fff2-a190-4635-ab27-6093acef9c15