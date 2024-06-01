class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:

        from collections import defaultdict
        graph = defaultdict(list)
        for u, v, w in edges:
            graph[u].append((v, w+1))
            graph[v].append((u, w+1))

        dist = [float("inf")]*n
        dist[0] = 0
        pq = [(0, 0)]
        while pq:
            distance, node = heappop(pq)
            for nei, n_wei in graph[node]:
                if distance + n_wei < dist[nei]:
                    dist[nei] = distance + n_wei
                    heappush(pq, (dist[nei], nei))

        ans = 0
        for u in range(len(dist)):
            if dist[u] <= maxMoves:
                ans += 1

        for u, v, w in edges:
            if dist[u] > maxMoves and dist[v] > maxMoves:
                continue

            cnt1 = max(0, maxMoves - dist[u])
            cnt2 = max(0, maxMoves - dist[v])

            ans += min(w, cnt1+cnt2)
        return ans
