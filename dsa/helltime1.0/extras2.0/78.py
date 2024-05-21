class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        out = []

        comb = 1 << len(nums)

        for mask in range(comb):
            subset = []
            for i in range(len(nums)):
                if mask & (1 << i):
                    subset.append(nums[i])
            out.append(subset)

        return out