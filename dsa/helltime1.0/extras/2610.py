class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        out = []
        while nums:
            tm = nums
            comb = []
            for i in range(len(nums)):
                if nums[i] not in comb:
                    comb.append(nums[i])
                    tm[i] = -1
            out.append(comb)
            nums = [i for i in tm if i != -1]
        return out
