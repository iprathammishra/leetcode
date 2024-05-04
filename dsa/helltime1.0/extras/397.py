class Solution:
    def integerReplacement(self, n: int) -> int:
        memo={}
        def dfs(k):
            if k==1:
                return 0
            if k in memo:
                return memo[k]
            cnt=float("inf")
            if k%2:
                cnt=min(cnt,dfs(k-1)+1,dfs(k+1)+1)
            else:
                cnt=min(cnt,dfs(k//2)+1)
            memo[k]=cnt
            return cnt
        return dfs(n)
