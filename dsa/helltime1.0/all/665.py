class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        def isSorted(arr: List[int]) -> bool:
            for i in range(len(arr) - 1):
                if (arr[i] > arr[i+1]):
                    return False
            return True
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                temp = nums[i]
                nums[i] = nums[i+1]
                if isSorted(nums):
                    return True
                nums[i] = temp
                nums[i+1] = temp
                return isSorted(nums)
        return True
