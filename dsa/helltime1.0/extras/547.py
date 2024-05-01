class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def dfs(node):
            if node not in self.visited:
                self.visited.add(node)
            for nei in gx[node]:
                if nei not in self.visited:
                    dfs(nei)
        n = len(isConnected)
        x = len(isConnected[0])
        gx = collections.defaultdict(list)
        for i in range(n):
            for j in range(x):
                if isConnected[i][j] == 1 and i != j:
                    gx[i+1].append(j+1)
                    gx[j+1].append(i+1)
        self.visited = set()
        cnt = 0
        for i in range(1, n+1):
            if i not in self.visited:
                dfs(i)
                cnt += 1
        return cnt
