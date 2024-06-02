class Solution:
    def minimumChairs(self, s: str) -> int:

        l_cnt = 0
        e_cnt = 0

        for ch in s:
            if ch == 'L':
                l_cnt += 1
            else:
                if l_cnt:
                    l_cnt -= 1
                else:
                    e_cnt += 1

        return e_cnt
