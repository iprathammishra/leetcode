class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> output(size);
        int left = 1;
        for (int i = 0; i < size; i++)
        {
            output[i] = left;
            left *= nums[i];
        }
        int right = 1;
        for (int i = size - 1; i >= 0; i--)
        {
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};