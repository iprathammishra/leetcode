class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> res(nums.begin(), nums.end());
        for (const int &num : nums)
        {
            res.push_back(num);
        }
        return res;
    }
};