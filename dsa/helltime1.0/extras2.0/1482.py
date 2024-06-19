class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        
        def process(mid):
            bouquests = 0
            cnt = 0
            for day in bloomDay:
                if day <= mid:
                    cnt += 1
                else:
                    cnt = 0

                if cnt == k:
                    bouquests += 1
                    cnt = 0
            
            return bouquests

        N = len(bloomDay)
        if m * k > N:
            return -1

        start = 0
        end = max(bloomDay)
        minDays = -1

        while start <= end:
            mid = (start + end) // 2
            if  process(mid) >= m:
                minDays = mid
                end = mid - 1
            else:
                start = mid + 1
        
        return minDays
