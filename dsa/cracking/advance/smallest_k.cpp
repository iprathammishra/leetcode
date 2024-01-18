// 14. **Smallest K:** Design an algorithm to find the smallest K numbers in an array.
#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> smallestK(std::vector<int> &vec, int k)
{
    std::sort(vec.begin(), vec.end());
    vec.erase(vec.begin() + k, vec.end());
    return vec;
}
int main()
{
    std::vector<int> nums = {3, 6, 2, 7, 8, 4, 9, 0, 2, 5, 4, 1, 6, 7};
    std::vector<int> result = smallestK(nums, 5);
    for (const int i : result)
        std::cout << i << " ";
    return 0;
}