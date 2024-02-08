class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int count = 0;
        for (const int &i : nums)
            if (i != val)
            {
                nums[count] = i;
                count++;
            }
        return count;
    }
};