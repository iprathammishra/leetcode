class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
        {
            return {0};
        }
        vector<vector<int>> adjacency_matrix(n);
        vector<int> degrees(n, 0);
        for (const vector<int> &edge : edges)
        {
            int node_a = edge[0];
            int node_b = edge[1];
            adjacency_matrix[node_a].push_back(node_b);
            adjacency_matrix[node_b].push_back(node_a);
            degrees[node_a]++;
            degrees[node_b]++;
        }
        queue<int> q;
        vector<int> ans_list;
        for (int i = 0; i < n; i++)
        {
            if (degrees[i] == 1)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            long long levels = q.size();
            ans_list.clear();
            for (int i = 0; i < levels; i++)
            {
                int curr = q.front();
                q.pop();
                ans_list.push_back(curr);
                for (const int &node : adjacency_matrix[curr])
                {
                    if (--degrees[node] == 1)
                        q.push(node);
                }
            }
        }
        return ans_list;
    }
};