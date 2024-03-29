class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        maxel = max(nums); 
        start, end, count, ans = 0, 0, 0, 0
        while start <= end and end < len(nums):
            if nums[end] == maxel:
                count += 1
            while count >= k:
                if nums[start] == maxel:
                    count -= 1    
                start += 1
                ans += len(nums) - end
            end += 1
        return ans