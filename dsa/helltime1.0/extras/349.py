class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        intersectionSet1 = set(nums1)
        intersectionSet2 = set(nums2)
        intersectionResult = intersectionSet1 & intersectionSet2
        return list(intersectionResult)
