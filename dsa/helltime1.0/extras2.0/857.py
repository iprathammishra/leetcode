class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        res=float("inf")
        pairs=[]
        for i in range(len(quality)):
            pairs.append([wage[i] / quality[i], quality[i]])
        pairs.sort(key=lambda p: p[0])
        
        mx_heap=[]
        t_quality=0
        for rate, quality in pairs:
            heappush(mx_heap, -quality)
            t_quality += quality

            if len(mx_heap) > k:
                t_quality += heappop(mx_heap)
            
            if len(mx_heap)==k:
                res=min(res, rate * t_quality)

        return res
