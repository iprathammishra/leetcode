class Solution:
    def checkValidString(self, s: str) -> bool:
        openbracket = 0
        for ch in s:
            if ch in "(*":
                openbracket += 1
            elif openbracket:
                openbracket -= 1
            else:
                return False
        closedbracket = 0
        for ch in s[::-1]:
            if ch in ")*":
                closedbracket += 1
            elif closedbracket:
                closedbracket -= 1
            else:
                return False
        return True