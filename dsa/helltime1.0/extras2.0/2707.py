class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        words = set(dictionary)

        @cache
        def dp(start):
            if start == len(s):
                return 0

            ans = 1 + dp(start+1)
            for end in range(start, len(s)):
                if s[start: end+1] in words:
                    ans = min(ans, dp(end+1))
            return ans

        return dp(0)
