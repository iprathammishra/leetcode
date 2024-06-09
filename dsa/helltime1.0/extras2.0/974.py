class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:

        remainder = {0: 1}
        res, N = 0, len(nums)

        cur_sum = 0
        for i in range(N):
            cur_sum += nums[i]
            remain = cur_sum % k

            if remain in remainder:
                res += remainder[remain]

            remainder[remain] = remainder.get(remain, 0) + 1

        return res
