class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        n = len(s)

        def func(idx, path):
            if idx == n:
                res.append(path[:])
                return

            for j in range(idx+1, n+1):
                if s[idx:j] == s[idx:j][::-1]:
                    func(j, path + [s[idx:j]])

        func(0, [])

        return res
