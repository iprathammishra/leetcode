// 18. **Shortest Supersequence:** You are given two arrays, one shorter (with all distinct elements) and one longer. Find the shortest subarray in the longer array that contains all the elements in the shorter array. The items can appear in any order.

// Example:<br>
// Input: {1, 5, 9} | {7, 5, 9, 0, 2, 1, 3, (5, 7, 9, 1), 1, 5, 8, 8, 9, 7}<br>
// Output: [7, 10] (the underlined portion above)
#include <iostream>
#include <unordered_map>
#include <vector>

std::pair<int, int> shortestSupersequence(const std::vector<int> &shorter, const std::vector<int> &longer)
{
    std::unordered_map<int, int> countMap;
    int requiredCount = shorter.size();

    for (int num : shorter)
    {
        countMap[num]++;
    }

    int left = 0, right = 0;
    int minLength = INT_MAX;
    std::pair<int, int> result = {-1, -1};

    while (right < longer.size())
    {
        if (countMap.find(longer[right]) != countMap.end() && countMap[longer[right]] > 0)
        {
            requiredCount--;
        }

        countMap[longer[right]]--;

        while (requiredCount == 0)
        {
            int currentLength = right - left + 1;
            if (currentLength < minLength)
            {
                minLength = currentLength;
                result = {left, right};
            }

            countMap[longer[left]]++;
            if (countMap[longer[left]] > 0)
            {
                requiredCount++;
            }

            left++;
        }

        right++;
    }

    return result;
}

int main()
{
    std::vector<int> shorter = {1, 5, 9};
    std::vector<int> longer = {7, 5, 9, 0, 2, 1, 3, 5, 7, 9, 1, 5, 8, 8, 9, 7};

    std::pair<int, int> result = shortestSupersequence(shorter, longer);

    std::cout << "Output: [" << result.first << ", " << result.second << "]" << std::endl;

    return 0;
}

// https://chat.openai.com/share/155c2f12-a165-46c6-88d8-90ac608ac03c