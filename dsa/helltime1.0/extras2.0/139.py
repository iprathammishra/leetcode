class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:

        queue = deque([0])
        visited = set()
        words = set(wordDict)

        while queue:
            start = queue.popleft()
            if start == len(s):
                return True

            for end in range(start+1, len(s)+1):
                if end in visited:
                    continue
                if s[start: end] in words:
                    queue.append(end)
                    visited.add(end)

        return False
