class Solution:
    def reorganizeString(self, s: str) -> str:
        count = Counter(s)
        maxlen = max(count.values())
        if maxlen > (len(s) + 1) // 2:
            return ""
        index = 0
        reorganize = [None] * len(s)
        for char, freq in count.most_common():
            while freq:
                reorganize[index] = char
                freq -= 1
                index += 2
                if index >= len(s):
                    index = 1
        return "".join(reorganize)
