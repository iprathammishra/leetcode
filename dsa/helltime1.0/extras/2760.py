class Solution:
    def longestAlternatingSubarray(self, nums: List[int], thres: int) -> int:
        mx,r,l=0,0,0
        while r<len(nums):
            if nums[r]%2==0 and nums[r]<=thres:
                l=r
                while r<len(nums)-1 and nums[r]%2!=nums[r+1]%2 and nums[r+1]<=thres:
                    r+=1
                mx=max(mx,r-l+1)
            r+=1
        return mx
            

