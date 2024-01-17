// 10. **Majority Element:** A majority element is an element that makes up more than half of the items in an array. Given a positive integers array, find the majority element. If there is no majority element, return -1. Do this in O(N) time and O(1) space.

// Example:
// Input: 1 2 5 9 5 9 5 5 5
// Output: 5
#include <iostream>
#include <unordered_map>
#include <vector>
int majorityElement(const std::vector<int> &vec)
{
    int size = vec.size();
    std::unordered_map<int, int> umap;
    for (const int i : vec)
        umap[i]++;
    for (const auto i : umap)
        if (i.second >= size / 2)
            return i.first;
    return -1;
}
int main()
{
    std::cout << majorityElement({1, 2, 5, 9, 5, 9, 5, 5, 5});
    return 0;
}