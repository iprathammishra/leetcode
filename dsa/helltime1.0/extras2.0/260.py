class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:

        cnt = Counter(nums)
        res = []

        for k, v in cnt.items():
            if v == 1:
                res.append(k)
        return res
