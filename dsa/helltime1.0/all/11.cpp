class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        while (left < right)
        {
            int current_area = (right - left) * min(height[left], height[right]);
            max_area = max(max_area, current_area);
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return max_area;
    }
};