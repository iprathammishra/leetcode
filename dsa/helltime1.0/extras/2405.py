class Solution:
    def partitionString(self, s: str) -> int:
        start = 0
        ans = 1
        for end in range(len(s)):
            count = Counter(s[start:end+1])
            val = list(count.values())
            if 2 in val:
                ans += 1
                start = end
        return ans
