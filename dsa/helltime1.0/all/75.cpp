class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        map<int, int> m;
        for (const auto it : nums)
        {
            m[it]++;
        }
        nums.clear();
        for (int i = 0; i < m[0]; i++)
        {
            nums.emplace_back(0);
        }
        for (int i = 0; i < m[1]; i++)
        {
            nums.emplace_back(1);
        }
        for (int i = 0; i < m[2]; i++)
        {
            nums.emplace_back(2);
        }
    }
};