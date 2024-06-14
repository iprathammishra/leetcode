class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        
        piles.sort()
        N = len(piles)
        
        cnt = 0
        x = N/3
        res = 0
        for i in range(1, N):
            if cnt == x:
                return res
            if i % 2:
                res += piles[-i-1]
                cnt += 1
            