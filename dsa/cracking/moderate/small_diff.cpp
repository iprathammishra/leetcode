// 6. **Smallest Difference:** Given two arrays of integers, computer the pair of values (one value in each array) with the smallest (non-negative) difference. Return the difference.

// Example:
// Input: {1, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
// Output: That is the pair {11, 8}.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
std::pair<int, int> smallestDifference(const std::vector<int>& arr1, const std::vector<int>& arr2)
{
    std::pair<int, int> result;
    std::vector<int> srtArr1 = arr1;
    std::vector<int> srtArr2 = arr2;
    std::sort(srtArr1.begin(), srtArr1.end());
    std::sort(srtArr2.begin(), srtArr2.end());

    int pointer1 = 0;
    int pointer2 = 0;
    int minDifference = INT_MAX;

    while(pointer1 < srtArr1.size() && pointer2 < srtArr2.size())
    {
        int currentDifference = std::abs(srtArr1[pointer1] - srtArr2[pointer2]);
        if (currentDifference < minDifference)
        {
            minDifference = currentDifference;
            result = {srtArr1[pointer1], srtArr2[pointer2]};
        }

        if (srtArr1[pointer1] < srtArr2[pointer2])
            ++pointer1;
        else
            ++pointer2;
    }

    return result;
}
int main() 
{   
    std::pair<int, int> result = smallestDifference({1, 3, 15, 11, 2}, {23, 127, 235, 19, 8});
    std::cout << "{" << result.first << ", " << result.second << "}" << std::endl;
}

// https://chat.openai.com/share/859fc02d-e675-49b3-bf43-2d34ab27f438