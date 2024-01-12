// 17. **Contiguous Sequence:** You are given an array of integers (both positive and negative). Find the contiguous sequence with the largest sum. Return the sum.

// Example:
// Input: 2, -8, 3, -2, 4, -10
// Output: 5 (i.e., {3, -2, 4})
#include <iostream>
#include <vector>
std::pair<int, int> contiguousSequence(const std::vector<int> &seq)
{
    if (seq.empty())
        return {-1, -1};
    int maxSum = seq[0];
    int currentSum = seq[0];
    int start = 0;
    int end = 0;
    int result = 0;
    int temp = 0;
    for (int i = 1; i < seq.size(); ++i)
    {
        if (seq[i] > (currentSum + seq[i]))
            start = i;
        currentSum = std::max(seq[i], currentSum + seq[i]);
        maxSum = std::max(maxSum, currentSum);
    }
    temp = start;
    end = start;
    while (true)
    {
        result += seq[temp];
        if (result == maxSum)
            return {start + 1, end + 1};
        temp++;
        end++;
    }
}
int main()
{
    std::vector<int> sequence = {2, -8, 3, -2, 4, -10};
    std::pair<int, int> pair = contiguousSequence(sequence);
    std::cout << pair.first << " " << pair.second << std::endl;
    return 0;
}