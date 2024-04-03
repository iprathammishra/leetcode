class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        diff = float('inf')
        res = []
        for i in range(1, len(arr)):
            if abs(arr[i] - arr[i-1]) < diff:
                diff = abs(arr[i] - arr[i-1])
                res = [[arr[i-1], arr[i]]]
            elif abs(arr[i] - arr[i-1]) == diff:
                res.append([arr[i-1], arr[i]])
        return res