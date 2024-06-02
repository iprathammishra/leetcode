class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:

        n = len(nums)
        start_prefix = []
        end_prefix = [0]

        cnt = 0
        for i in range(n):
            cnt += nums[i]
            start_prefix.append(cnt)

        cnt = 0
        for i in range(n-1, -1, -1):
            cnt += nums[i]
            end_prefix.append(cnt)

        end_prefix = end_prefix[::-1][1:]

        res = float("inf")
        for i in range(n):
            x = start_prefix[i]//(i+1)
            y = end_prefix[i]//((n-i-1) if (n-i-1) else 1)
            if abs(x-y) < res:
                ans = i
                res = abs(x-y)

        return ans
