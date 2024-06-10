class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        nums = sorted(nums, key=lambda x: (len(x), int(x)))
        return nums[len(nums)-k]
