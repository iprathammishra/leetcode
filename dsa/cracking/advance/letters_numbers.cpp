// 5. **Letters and Numbers:** Given an array filled with letters and numbers, find the longest subarray with an equal number of letters and numbers.
#include <iostream>
#include <unordered_map>
#include <vector>
std::vector<char> longestSubarrayWithEqualCounts(const std::vector<char> &arr)
{
    int longestLength = 0, start = -1, letterCount = 0, numberCount = 0;
    std::unordered_map<int, int> countMap{{0, -1}};

    for (int i = 0; i < arr.size(); ++i)
    {
        isalpha(arr[i]) ? ++letterCount : ++numberCount;
        int countDifference = letterCount - numberCount;

        if (countMap.count(countDifference))
        {
            int currentLength = i - countMap[countDifference];
            if (currentLength > longestLength)
            {
                longestLength = currentLength;
                start = countMap[countDifference] + 1;
            }
            else
                countMap[countDifference] = i;
        }
    }

    return {arr.begin() + start, arr.begin() + start + longestLength};
}
int main()
{
    std::vector<char> arr = {'a', '1', 'b', '2', '3', 'd', '4', '5', '6', 'e'};
    std::vector<char> result = longestSubarrayWithEqualCounts(arr);
    for (char element : result)
        std::cout << element << " ";
    return 0;
}

// https://chat.openai.com/share/5100537e-d661-422c-a94e-b4b6026cbb3f