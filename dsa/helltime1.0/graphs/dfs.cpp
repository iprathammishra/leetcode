class Solution
{
private:
    void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &res)
    {
        visited[node] = true;
        res.emplace_back(node);
        for (int adjacent : adj[node])
        {
            if (!visited[adjacent])
            {
                dfs(adjacent, adj, visited, res);
            }
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<int> res;
        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, res);
            }
        }
        return res;
    }
};