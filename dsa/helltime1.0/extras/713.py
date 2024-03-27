class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        left, product, count = 0, 1, 0
        for right, value in enumerate(nums):
            product *= value
            while left <= right and product >= k:
                product //= nums[left]; left += 1
            count += right - left + 1
        return count