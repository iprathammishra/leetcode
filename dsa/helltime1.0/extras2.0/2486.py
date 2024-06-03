class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        
        start_t = 0
        start_s = 0

        while start_s < len(s) and start_t < len(t):
            if s[start_s] == t[start_t]:
                start_t += 1
            start_s += 1

        return len(t) - start_t
