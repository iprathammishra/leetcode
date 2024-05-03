# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        def dfs(node):
            if not node:
                return 
            dfs(node.left)
            self.arr.append(node)
            dfs(node.right)
        def construct(left,right,path):
            if left>right:
                return None
            middle=(left+right)//2
            path[middle].left=construct(left,middle-1,path)
            path[middle].right=construct(middle+1,right,path)
            return path[middle]
        self.arr=[]
        dfs(root)
        return construct(0,len(self.arr)-1,self.arr)