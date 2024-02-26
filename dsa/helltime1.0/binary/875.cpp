class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1;
        int right = 1e9;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int hoursSpent = 0;
            for (int pile : piles)
            {
                hoursSpent += (pile + mid - 1) / mid;
            }

            if (hoursSpent <= h)
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