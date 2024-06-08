class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        remainder_map = {0: -1}
        cur_sum = 0

        for i in range(len(nums)):
            cur_sum += nums[i]
            remainder = cur_sum % k

            if remainder in remainder_map:
                if i - remainder_map[remainder] > 1: # for at least two
                    return True
            else:
                remainder_map[remainder] = i

        return False
