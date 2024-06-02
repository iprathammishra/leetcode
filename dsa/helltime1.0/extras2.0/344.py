class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        n = len(s)
        start = 0
        end = n - 1
        while start < end:
            s[start], s[end] = s[end], s[start]
            start += 1
            end -= 1
