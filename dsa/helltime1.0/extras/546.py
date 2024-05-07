class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        @cache
        def dfs(left, right, cnt=0):
            if left > right:
                return 0
            while left+1 <= right and boxes[left] == boxes[left+1]:
                left += 1
                cnt += 1
            ans = (cnt+1)**2+dfs(left+1, right)
            for i in range(left+1, right+1):
                if boxes[i] == boxes[left]:
                    ans = max(ans, dfs(i, right, cnt+1) +
                              dfs(left+1, i-1, cnt=0))
            return ans
        return dfs(0, len(boxes)-1)
