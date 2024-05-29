class Solution:
    def numSteps(self, s: str) -> int:
        cnt = 0
        x = int(s, 2)
        while x != 1:
            if not x % 2:
                cnt += 1
                x //= 2
            else:
                cnt += 1
                x += 1
        return cnt
