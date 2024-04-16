# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        self.cnt=0
        def dfs(node):
            if not node:
                return 0,0
            leftsum,leftcnt=dfs(node.left)
            rightsum,rightcnt=dfs(node.right)
            totalsum=node.val+leftsum+rightsum
            totalcnt=1+leftcnt+rightcnt
            if totalsum//totalcnt==node.val:
                self.cnt+=1
            return totalsum,totalcnt
        dfs(root)
        return self.cnt