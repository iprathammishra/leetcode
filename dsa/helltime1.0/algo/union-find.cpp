class DisjointUnionSet
{
    vector<int> rank, parent;
    int n;

public:
    DisjointUnionSet(int n)
    {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union(int x, int y)
    {
        if xRoot
            = find(x), yRoot = find(y);
        if (xRoot == yRoot)
        {
            return;
        }
        if (rank[xRoot] < rank[yRoot])
        {
            parent[xRoot] = yRoot;
        }
        else if (rank[yRoot] < rank[xRoot])
        {
            parent[yRoot] = xRoot;
        }
        else
        {
            parent[yRoot] = xRoot;
            rank[xRoot] = rank[xRoot] + 1;
        }
    }
};