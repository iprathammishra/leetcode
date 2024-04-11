class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last = {char:index for index, char in enumerate(s)}
        size = 0
        end = 0
        output = []
        for index, char in enumerate(s):
            size += 1
            end = max(end, last[char])
            if index == end:
                output.append(size)
                size = 0
        return output
