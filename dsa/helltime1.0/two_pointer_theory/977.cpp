class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> res;
        for (const int &i : nums)
            res.push_back(i * i);
        sort(res.begin(), res.end());
        return res;
    }
};