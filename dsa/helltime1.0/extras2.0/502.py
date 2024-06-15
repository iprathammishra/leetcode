class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:

        arr = []
        heap = []
        N = len(profits)

        arr = [(capital[i], profits[i]) for i in range(N)]
        
        arr.sort()
        runner = 0
        while k:
            while runner < N and arr[runner][0] <= w:
                heappush(heap, -arr[runner][1])
                runner += 1
            if not heap:
                break
            w -= heappop(heap)
            k -= 1

        return w
