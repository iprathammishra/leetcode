/*
Description:

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> TwoSum(vector<int> sum, int target)
{
    vector<int> result;
    for (int i = 0; i < sum.size(); i++)
    {
        for (int j = i + 1; j < sum.size(); j++)
        {
            if (sum[i] + sum[j] == target)
            {
                result.push_back(i);
                result.push_back(j);
            }
        }
    }
    return result;
}
int main()
{
    vector<int> r = TwoSum({2, 4, 5, 6}, 9);
    for (int element : r)
    {
        cout << element << " ";
    }
    return 0;
}