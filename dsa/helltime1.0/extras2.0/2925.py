class Solution:
    def maximumScoreAfterOperations(self, edges: List[List[int]], values: List[int]) -> int:
        n = len(values)
        from collections import defaultdict
        graph = defaultdict(list)

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        subtree = [0]*n
        for i in range(n):
            subtree[i] = values[i]

        def pre_process(node, parent):
            nonlocal subtree

            for child in graph[node]:
                if child != parent:
                    pre_process(child, node)
                    subtree[node] += subtree[child]

        pre_process(0, -1)
        dp = [-1]*n

        def dfs(node, parent):
            nonlocal dp

            dp[node] = subtree[node] - values[node]

            cnt, sm = 0, 0
            for child in graph[node]:
                if child != parent:
                    dfs(child, node)
                    cnt += 1
                    sm += dp[child]
                if cnt > 0:
                    dp[node] = max(dp[node], values[node] + sm)

        dfs(0, -1)
        return dp[0]
