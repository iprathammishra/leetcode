# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        self.con=[]
        mp=defaultdict(str)
        s="abcdefghijklmnopqrstuvwxyz"
        for i in range(0,26):
            mp[i]=s[i]
        def dfs(node,ch):
            if not node:
                return 
            if not node.left and not node.right:
                ch+=mp[node.val]
                self.con.append(ch[::-1])
                return
            dfs(node.left,ch+mp[node.val])
            dfs(node.right,ch+mp[node.val])
        dfs(root,"")
        self.con.sort()
        return self.con[0]
