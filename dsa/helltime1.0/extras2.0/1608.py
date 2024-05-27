class Solution:
    def specialArray(self, nums: List[int]) -> int:
        mx = max(nums)
        for x in range(mx, -1, -1):
            cnt = 0
            for num in nums:
                if num >= x:
                    cnt += 1
            if cnt == x:
                return x

        return -1
