# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        stk = []
        cur = root
        vx = []
        while cur or stk:
            while cur:
                stk.append(cur)
                cur = cur.left
            cur = stk[-1]
            stk.pop()
            vx.append(cur.val)
            cur = cur.right
        vx.sort()
        x = [vx[0]]
        for v in vx:
            if x[-1] != v:
                x.append(v)
        return x[1] if len(x) > 1 else -1
