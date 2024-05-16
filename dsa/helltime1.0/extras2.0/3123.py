class Solution:
    def findAnswer(self, n: int, edges: List[List[int]]) -> List[bool]:
        from collections import defaultdict
        graph = defaultdict(list)
        for u, v, w in edges:
            graph[u].append([v, w])
            graph[v].append([u, w])

        def func(src):
            distance = [float("inf")]*n
            distance[src] = 0
            pq = [(0, src)]
            while pq:
                cost, node = heappop(pq)
                if distance[node]==cost:
                    for nei, wei in graph[node]:
                        if cost+wei < distance[nei]:
                            distance[nei] = cost+wei
                            heappush(pq, (cost+wei, nei))
            return distance

        d0, d1 = func(0), func(n-1)
        out=[]
        for u, v, w in edges:
            out.append(
                d0[n-1] < inf and
                (
                    d0[u] + d1[v] + w == d0[n-1] or
                    d0[v] + d1[u] + w == d0[n-1]
                )
            )
        return out