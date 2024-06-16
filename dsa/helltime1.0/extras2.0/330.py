class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        
        ans = 0
        idx = 0
        missing = 1
        N = len(nums)

        while missing <= n:
            if idx < N and nums[idx] <= missing:
                missing += nums[idx]
                idx += 1
            else:
                missing += missing
                ans += 1

        return ans
