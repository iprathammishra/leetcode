// 16. **Sub Sort:** Given an array of integers, write a method to find indices m and n such that if you sorted elements m through n, the entire array would be stored. Minimize n - m (that is, find the smallest such sequence).

// Example:
// Input: 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19
// Output: (3, 9)
#include <iostream>
#include <vector>
#include <algorithm>
std::pair<int, int> findSubSortIndices(const std::vector<int>& arr) {
    int n = arr.size();

    // Find the left bound of the unsorted sequence
    int left = 0;
    while (left < n - 1 && arr[left] <= arr[left + 1]) {
        left++;
    }

    // If the array is already sorted, no need to proceed
    if (left == n - 1) {
        return std::make_pair(-1, -1); // Indicates already sorted
    }

    // Find the right bound of the unsorted sequence
    int right = n - 1;
    while (right > 0 && arr[right] >= arr[right - 1]) {
        right--;
    }

    // Find the minimum and maximum values within the unsorted sequence
    int min_in_unsorted = *std::min_element(arr.begin() + left, arr.begin() + right + 1);
    int max_in_unsorted = *std::max_element(arr.begin() + left, arr.begin() + right + 1);

    // Expand the left bound to include elements smaller than the minimum
    while (left >= 0 && arr[left] > min_in_unsorted) {
        left--;
    }

    // Expand the right bound to include elements larger than the maximum
    while (right < n && arr[right] < max_in_unsorted) {
        right++;
    }

    return std::make_pair(left + 1, right - 1);

}
int main()
{
    std::vector<int> arr = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    std::pair<int, int> result = findSubSortIndices(arr);

    if (result.first == -1 && result.second == -1) {
        std::cout << "The array is already sorted." << std::endl;
    } else {
        std::cout << "Indices to sort the array: (" << result.first << ", " << result.second << ")" << std::endl;
    }

    return 0;
}

// https://chat.openai.com/share/18e9af80-67bb-42ea-b49c-0cb21e688079