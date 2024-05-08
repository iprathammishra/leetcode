class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        x = score.copy()
        x.sort(reverse=True)
        mp = {}
        for idx, val in enumerate(x, 1):
            mp[val] = idx
        out = []
        print(mp)
        for sc in score:
            if mp[sc] == 1:
                out.append("Gold Medal")
            elif mp[sc] == 2:
                out.append("Silver Medal")
            elif mp[sc] == 3:
                out.append("Bronze Medal")
            else:
                out.append(str(mp[sc]))
        return out
