class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int num1Index = m - 1;
        int num2Index = n - 1;
        int mergedIndex = m + n - 1;
        while (num2Index >= 0)
        {
            if (num1Index >= 0 && nums1[num1Index] > nums2[num2Index])
            {
                nums1[mergedIndex] = nums1[num1Index];
                num1Index--;
            }
            else
            {
                nums1[mergedIndex] = nums2[num2Index];
                num2Index--;
            }
            mergedIndex--;
        }
    }
};
