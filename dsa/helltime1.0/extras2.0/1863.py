class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        n = len(nums)
        subsets = []
        comb = 1 << n
        res = 0

        for mask in range(comb):

            subset = []
            for i in range(n):
                if mask & (1 << i):
                    subset.append(nums[i])

            x = 0
            for i in range(len(subset)):
                x ^= subset[i]
            res += x

        return res
