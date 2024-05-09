class Solution:
    def __init__(self):
        self.CUR_DFS=1

    def countVisitedNodes(self, edges: List[int]) -> List[int]:
        def dfs(node):
            if out[node]!=-1:
                return
            if visited[node]==self.CUR_DFS:
                length=1
                curr=node
                while edges[curr]!=node:
                    length+=1
                    curr=edges[curr]
                curr=node
                while edges[curr]!=node:
                    out[curr]=length
                    curr=edges[curr]
                out[curr]=length
                return
            visited[node]=self.CUR_DFS
            dfs(edges[node])
            if out[node]==-1:
                out[node]=out[edges[node]]+1

        n=len(edges)
        out=[-1]*n
        visited=[0]*n
        for i in range(n):
            dfs(i)
        return out