# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def rec(t1: Optional[TreeNode], t2: Optional[TreeNode]) -> bool:
            if t1 is None and t2 is None: return True
            if t1 is None or t2 is None: return False
            return (
                t1.val == t2.val and
                rec(t1.left, t2.left) and 
                rec(t1.right, t2.right)
            )
        if root is None: return False
        return (
            rec(root, subRoot) or
            self.isSubtree(root.left, subRoot) or
            self.isSubtree(root.right, subRoot)
        )