class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        tx = []
        for i in range(len(nums)):
            tx.insert(index[i], nums[i])
        return tx
