class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &s)
    {
        visited[node] = true;
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, adj, visited, s);
            }
        }
        s.push(node);
    }
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, s);
            }
        }
        vector<int> result;
        while (!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};