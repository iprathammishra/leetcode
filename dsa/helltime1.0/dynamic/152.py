class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = max(nums)
        curMax, curMin = 1, 1
        for num in nums:
            temp = num*curMax
            curMax = max(num, num*curMax, num*curMin)
            curMin = min(num, temp, num*curMin)
            res = max(res, curMax)
        return res
