class Solution:
    def rob(self, nums: List[int]) -> int:
        return max(nums[0], self.helper(nums[1:]), self.helper(nums[:-1]))

    def helper(self, nums: List[int]) -> int:
        left, right = 0, 0
        for num in nums:
            temp = max(num + left, right)
            left = right
            right = temp
        return right
