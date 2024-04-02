class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        def dfs(left: int, right: int) -> int:
            counter = Counter(s[left:right+1])
            oddch = next((ch for ch, fr in counter.items() if fr < k), None)
            if oddch is None:
                return right - left + 1
            i = left
            max_length = 0
            while i <= right:
                while i <= right and s[i] == oddch:
                    i += 1
                if i > right:
                    break
                j = i
                while j <= right and s[j] != oddch:
                    j += 1
                cur_length = dfs(i, j - 1)
                max_length = max(max_length, cur_length)
                i = j
            return max_length
        return dfs(0, len(s) - 1)
