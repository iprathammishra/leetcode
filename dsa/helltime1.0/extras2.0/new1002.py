class Solution:
    def commonChars(self, words: List[str]) -> List[str]:

        res = []

        n = len(words)
        comp = words[0]
        fp = {}

        for c in comp:
            fp[c] = fp.get(c, 0) + 1
            bx = True
            for i in range(n):
                cnt = Counter(words[i])
                if fp[c] > cnt[c]:
                    bx = False
                    break

            if bx:
                res.append(c)

        return res
