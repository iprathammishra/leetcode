// 24. **Pairs with Sum:** Design an algorithm to find all pairs of integers within an array which sum to a specified value.
#include <iostream>
#include <unordered_set>
#include <vector>
std::pair<int, int> pairWithSum(const std::vector<int> &array, const int &targetSum)
{
    std::unordered_set<int> seenNumbers;
    for (int num : array)
    {
        int complement = targetSum - num;
        if (seenNumbers.find(complement) != seenNumbers.end())
            return {num, complement};
        seenNumbers.insert(num);
    }
}
int main()
{
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int targetSum = 10;
    std::pair<int, int> pairs = pairWithSum(array, targetSum);
    std::cout << pairs.first << " " << pairs.second;
    return 0;
}

// https://chat.openai.com/share/9d6920ee-e6cd-4ec7-a5f0-610259eaeb7c