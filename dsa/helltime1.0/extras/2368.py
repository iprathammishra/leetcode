class Solution:
    def reachableNodes(self, n: int, edges: List[List[int]], rx: List[int]) -> int:
        gx = collections.defaultdict(list)
        for u, v in edges:
            gx[u].append(v)
            gx[v].append(u)
        vx = set(rx)
        q = deque([0])
        cnt = 0
        while q:
            for _ in range(len(q)):
                node = q.popleft()
                if node not in vx:
                    cnt += 1
                    vx.add(node)
                for n in gx[node]:
                    if n not in vx:
                        cnt += 1
                        vx.add(n)
                        q.append(n)
        return cnt
