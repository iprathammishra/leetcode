class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int positiveIndex = 0;
        int negativeIndex = 1;
        vector<int> result(nums.size());
        for (const int &num : nums)
        {
            if (num > 0)
            {
                result[positiveIndex] = num;
                positiveIndex += 2;
            }
            else
            {
                result[negativeIndex] = num;
                negativeIndex += 2;
            }
        }
        return result;
    }
};