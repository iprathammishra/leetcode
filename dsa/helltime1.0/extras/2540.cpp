class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int one = 0;
        int two = 0;
        while (one < nums1.size() && two < nums2.size())
        {
            if (nums1[one] == nums2[two])
            {
                return nums1[one];
            }
            if (nums1[one] < nums2[two])
            {
                one++;
            }
            else
            {
                two++;
            }
        }
        return -1;
    }
};