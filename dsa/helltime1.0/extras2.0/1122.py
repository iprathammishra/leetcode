class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        cnt = collections.Counter(arr1)
        out = []
        for arr in arr2:
            x = [arr]*cnt[arr]
            out.extend(x)
        y = []
        for arr in arr1:
            if arr not in arr2:
                y.append(arr)
        return out+sorted(y)
