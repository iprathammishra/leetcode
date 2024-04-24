class Solution:
    def tribonacci(self, n: int) -> int:
        ans = [0, 1, 1]
        for i in range(3, n+1):
            ans.append(ans[i-1]+ans[i-2]+ans[i-3])
        return ans[n]
