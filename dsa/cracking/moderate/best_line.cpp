// 14. **Best Line:** Given a two-dimensional graph with points on it, find a line which passes the most number of points.
#include <iostream>
#include <vector>
#include <unordered_map>
struct Point
{
    double x, y;
    Point(double _x, double _y) : x(_x), y(_y) {}
};
std::pair<double, double> findBestLine(const std::vector<Point>& points)
{
    std::unordered_map<double, int> slopeCount;
    int maxCount = 0;
    std::pair<double, double> bestline;

    for (int i = 0; i < points.size(); ++i)
        for (int j = i + 1; j < points.size(); ++j)
        {
            double slope, intercept;
            if (points[i].x == points[j].x)
            {
                slope = std::numeric_limits<double>::infinity();
                intercept = points[i].x;
            }
            else
            {
                slope = (points[j].y - points[i].y) / (points[j].x - points[i].x);
                intercept = points[i].y - slope * points[i].x;
            }

            ++slopeCount[slope];

            if (slopeCount[slope] > maxCount)
            {
                maxCount = slopeCount[slope];
                bestline = std::make_pair(slope, intercept);
            }
        }
    return bestline;
}
int main()
{
    std::vector<Point> points = {{1, 3}, {2, 5}, {3, 7}, {4, 9}, {5, 11}};
    
    std::pair<double, double> bestLine = findBestLine(points);

    std::cout << "Best Line: y = " << bestLine.first << "x + " << bestLine.second << std::endl;
    return 0;
}

// Brute Force: Check all possible pairs of points, calculate slopes and intercepts, count points on each line, and keep track of the best one.

// https://chat.openai.com/c/ea6351c4-c470-4b2d-988a-0e618d11d101