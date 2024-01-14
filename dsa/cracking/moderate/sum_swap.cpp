// 21. **Sum Swap:** Given two arrays of integers, find a pair of values (one values from each arrays) that you can swap to give the two arrays the same sum.

// Example:
// Input: [4, 1, 2, 1, 1, 2] and [3, 6, 3, 3] <br>
// Output: {1, 3}
#include <iostream>
#include <vector>
#include <unordered_set>
std::pair<int, int> findSumSwapPair(const std::vector<int> &arr1, const std::vector<int> &arr2)
{
    int sum1 = 0;
    int sum2 = 0;
    for (int i : arr1)
        sum1 += i;
    for (int i : arr2)
        sum2 += i;
    int targetDifference = (sum1 - sum2) / 2;
    std::unordered_set<int> unSET(arr2.begin(), arr2.end());
    for (int num : arr1)
    {
        int complement = num - targetDifference;
        if (unSET.find(complement) != unSET.end())
            return {num, complement};
    }
    return {-1, -1};
}
int main()
{
    std::vector<int> arr1 = {4, 1, 2, 1, 1, 2};
    std::vector<int> arr2 = {3, 6, 3, 3};
    std::pair<int, int> pair = findSumSwapPair(arr1, arr2);
    std::cout << pair.first << " " << pair.second << std::endl;
    return 0;
}

// Question:
// What is the difference in between:

// int sum1 = 0; int sum2 = 0;

// and

// int sum1, sum2 = 0;

// In C++, the two snippets you provided are not equivalent.

// Answer:
// int sum1 = 0; int sum2 = 0; This snippet declares two integers, sum1 and sum2, and initializes both of them to 0.

// int sum1, sum2 = 0; This snippet declares two integers, sum1 and sum2, but only initializes sum2 to 0. sum1 is left uninitialized, which means it could contain any value (it's undefined).

// So, if you want to initialize both sum1 and sum2 to 0, you should use the first snippet. If you only want to initialize sum2 to 0 and leave sum1 uninitialized, you should use the second snippet. However, leaving variables uninitialized can lead to unpredictable behavior and is generally considered bad practice.

// https://chat.openai.com/share/c44f548d-dc07-4116-9ee6-867e300099f6
