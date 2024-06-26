class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        # m = float("-inf")
        # for i in range(len(nums)):
        #     for j in range(i, len(nums)):
        #         currm = nums[i] ^ nums[j]
        #         m = max(m, currm)
        # return m
        maxNum = max(nums)
        if maxNum == 0:
            return 0
        maxBit = int(math.log2(maxNum))
        ans = 0
        mask = 0

        for i in range(maxBit, -1, -1):
            mask |= 1 << i
            prefixes = set([num & mask for num in nums])
            candidate = ans | 1 << i
            for prefix in prefixes:
                if prefix ^ candidate in prefixes:
                    ans = candidate
                    break

        return ans
