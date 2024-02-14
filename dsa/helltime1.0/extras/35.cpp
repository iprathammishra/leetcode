class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        auto it = find(nums.begin(), nums.end(), target);
        if (it != nums.end())
            return distance(nums.begin(), it);
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > target)
                    return i;
            }
            return nums.size();
        }
    }
};