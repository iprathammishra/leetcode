class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        adj = collections.defaultdict(list)
        nodes = []
        for u, v in paths:
            adj[u].append(v)
            if u not in nodes:
                nodes.append(u)
            if v not in nodes:
                nodes.append(v)
        keys = list(adj.keys())
        for node in nodes:
            if node not in keys:
                return node
        return ""
