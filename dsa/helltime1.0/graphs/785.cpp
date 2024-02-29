class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int numNodes = graph.size();
        vector<int> colors(numNodes, 0);
        function<bool(int, int)> dfs = [&](int currentNode, int currentColor) -> bool
        {
            colors[currentNode] = currentColor;
            for (int adjacentNode : graph[currentNode])
            {
                if (colors[adjacentNode] == 0)
                {
                    if (!dfs(adjacentNode, 3 - currentColor))
                    {
                        return false;
                    }
                }
                else if (colors[adjacentNode] == currentColor)
                {
                    return false;
                }
            }
            return true;
        };
        for (int node = 0; node < numNodes; node++)
        {
            if (colors[node] == 0 && !dfs(node, 1))
            {
                return false;
            }
        }
        return true;
    }
};