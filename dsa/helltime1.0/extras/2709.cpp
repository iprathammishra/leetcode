const int MAX_VALUE = 100010;
vector<int> prime_factors[MAX_VALUE];

int init = []()
{
    for (int x = 1; x < MAX_VALUE; ++x)
    {
        int value = x;
        int divisor = 2;
        while (divisor <= value / divisor)
        {
            if (value % divisor == 0)
            {
                prime_factors[x].push_back(divisor);
                while (value % divisor == 0)
                {
                    value /= divisor;
                }
            }
            ++divisor;
        }
        if (value > 1)
        {
            prime_factors[x].push_back(value);
        }
    }
    return 0;
}();

class UnionFind
{
public:
    UnionFind(int n) : parent(n), rank(n, 1), count(n)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    bool unite(int a, int b)
    {
        int rootA = find(a), rootB = find(b);
        if (rootA == rootB)
        {
            return false;
        }
        if (rank[rootA] > rank[rootB])
        {
            parent[rootB] = rootA;
            rank[rootA] += rank[rootB];
        }
        else
        {
            parent[rootA] = rootB;
            rank[rootB] += rank[rootA];
        }
        --count;
        return true;
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    int getCount() const
    {
        return count;
    }

private:
    vector<int> parent, rank;
    int count;
};

class Solution
{
public:
    bool canTraverseAllPairs(vector<int> &nums)
    {
        int maxNum = *max_element(nums.begin(), nums.end());
        int size = nums.size();
        UnionFind uf(maxNum + size + 1);

        for (int i = 0; i < size; ++i)
        {
            for (int factor : prime_factors[nums[i]])
            {
                uf.unite(i, factor + size);
            }
        }

        unordered_set<int> distinctRoots;
        for (int i = 0; i < size; ++i)
        {
            distinctRoots.insert(uf.find(i));
        }
        return distinctRoots.size() == 1;
    }
};