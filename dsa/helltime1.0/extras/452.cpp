class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](const vector<int> &point1, const vector<int> &point2)
             { return point1[1] < point2[1]; });
        int ans = 0;
        int lastShotArrow = -(1LL << 60);
        for (const auto &point : points)
        {
            int start = point[0];
            int end = point[1];
            if (start > lastShotArrow)
            {
                ans++;
                lastShotArrow = end;
            }
        }
        return ans;
    }
};