class Solution:
    def longestPalindrome(self, s: str) -> int:
        
        cnt = Counter(s)
        res = 0
        bx = False

        for v in cnt.values():
            if not v%2:
                res += v
            else:
                res += (v - 1)
                bx = True

        if bx:
            return res + 1
        
        return res
