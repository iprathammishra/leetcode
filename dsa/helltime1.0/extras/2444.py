from typing import List


class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        l_far = l_near = right = -1
        res = 0
        for index, num in enumerate(nums):
            if not minK <= num <= maxK:
                l_far = index
            if num == minK:
                l_near = index
            if num == maxK:
                right = index
            res += max(0, min(l_near, right) - l_far)
        return res
