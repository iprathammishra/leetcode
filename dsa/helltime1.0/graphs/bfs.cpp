class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<int> res;
        queue<int> queue;
        visited[0] = true;
        queue.push(0);
        while (!queue.empty())
        {
            int front = queue.front();
            res.emplace_back(front);
            queue.pop();
            for (auto &adjacent : adj[front])
            {
                if (!visited[adjacent])
                {
                    visited[adjacent] = true;
                    queue.push(adjacent);
                }
            }
        }
        return res;
    }
};