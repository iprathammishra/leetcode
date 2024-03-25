class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int left = 1;
        int right = arr.size() - 2;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] > arr[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};