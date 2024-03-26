class Solution:
    def countBits(self, n: int) -> List[int]:
        def helper(s: str) -> int:
            count = 0
            for bit in s:
                if bit == '1':
                    count += 1
            return count
        ans = []
        for i in range(n+1):
            ans.append(helper(str(bin(i))))
        return ans
