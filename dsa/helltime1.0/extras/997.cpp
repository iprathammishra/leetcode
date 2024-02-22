class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> trust_others(n + 1, 0);
        vector<int> trust_by_others(n + 1, 0);
        for (const vector<int> &relation : trust)
        {
            int truster = relation[0];
            int trustee = relation[1];
            trust_others[truster]++;
            trust_by_others[trustee]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (trust_others[i] == 0 && trust_by_others[i] == n - 1)
                return i;
        }
        return -1;
    }
};