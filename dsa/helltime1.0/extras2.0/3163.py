
class Solution:
    def compressedString(self, word: str) -> str:
        comp = ""
        cnt = 1
        for i in range(1, len(word)):
            if word[i] == word[i-1]:
                cnt += 1
                if cnt == 9:
                    comp += ("9"+word[i-1])
                    cnt = 0
            else:
                if cnt:
                    comp += (str(cnt)+word[i-1])
                cnt = 1

        if cnt:
            comp += (str(cnt)+word[-1])

        return comp
