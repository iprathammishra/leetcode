// 4. **Missing Number:** An array A contains all the integers from 0 to n, except for one number which is missing. In this problem, we cannot access an entire integer in A with a single operation. The element of A are represented in binary, and the only operation we can use to access them is "fetch the jth bit of A[i]," which takes constant time. Write code to find the missing integer. Can you do it in O(n) time?
#include <iostream>
#include <vector>
int findMissingNumber(const std::vector<int> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
        if (nums[i] != i)
            return i;
    return -1;
}

int main()
{
    std::vector<int> nums = {0, 1, 2, 3, 4};
    int result = findMissingNumber(nums);
    std::cout << "The missing number is: " << result << std::endl;
    return 0;
}
