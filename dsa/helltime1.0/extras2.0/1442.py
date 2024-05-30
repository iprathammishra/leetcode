class Solution:
    def countTriplets(self, arr: List[int]) -> int:

        cnt = 0
        for i in range(len(arr)-1):
            XOR = 0
            for k in range(i, len(arr)):
                XOR ^= arr[k]
                if not XOR:
                    cnt += (k-i)

        return cnt
