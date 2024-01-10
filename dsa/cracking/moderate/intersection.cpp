// 3. **Intersection:** Given two straight line segements (represented as a start point and an end point), computer the point of intersection, if any.
#include <iostream>
#include <cmath>
struct Points
{
    double x, y;
};
Points findIntersection(const double& a1, const double& b1, const double& c1, const double& a2, const double& b2, const double& c2)
{
    Points point;
    double denominator = (a1*b2 - a2*b1);
    if (std::abs(denominator) < 1e-6)
        {point.x = point.y = NAN;
        return point;}
    point.x = (b1*c2 - b2*c1)/denominator;
    point.y = (a2*c1 - a1*c2)/denominator;
    return point;
}
int main()
{
    Points intersection = findIntersection(2, 4, 6, 4, 8, 6);
    if (!std::isnan(intersection.x) && !std::isnan(intersection.y))
        std::cout << "Intersection x and y: " << intersection.x << " and " << intersection.y;
    else
        std::cout << "No intersection point.";
    return 0;
}

// For calculating the slope: y2 - y1 / x2 - x1 = m
// For calculating the equation of the line: y - y1 = m (x - x1)
// For calculating the intersection points:
// x = b1c2 - b2c1/a1b2 - a2b1
// y = a2c1 - a1c2/a1b2 - a2b1