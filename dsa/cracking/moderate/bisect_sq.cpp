// 13. **Bisect Squares:** Given two squares on a two-dimensional place, find a line that would cut these two squares in half. Assume that the top and the bottom sides of the square run parallel to the x-axis.
#include <iostream>
class BisectLines
{
    public:
        std::pair<double, double> center(double x, double y, double length)
        const {
            std::pair<double, double> point;
            point.first =  (x + length/2);
            point.second =  (y + length/2);
            return point;
        }
        double slope(double x1, double y1, double x2, double y2)
        const {
            return ((y2 - y1)/(x2 - x1));
        }
        double yIntercept(double x, double y, double slope)
        const {
            return ((slope * x) - y) * (-1);
        }
        std::pair<double, double> midpoint(double x1, double y1, double x2, double y2)
        const {
            double x = (x1 + x2)/2;
            double y = (y1 + y2)/2;
            std::pair<double, double> point;
            point.first = x;
            point.second = y;
            return point;
        }
        bool validateBisectingPoint(std::pair<double, double> point, double slope, double intercept)
        const {
            return (point.second == (slope * point.first) - intercept*(-1));
        }
};
int main()
{
    BisectLines bisectlines;
    std::pair<double, double> vp, c1, c2;
    c1 = bisectlines.center(0, 0, 4);
    c2 = bisectlines.center(2, 3, 5);
    vp = bisectlines.midpoint(
        c1.first, c1.second, c2.first, c2.second
    );
    double slope = bisectlines.slope(c1.first, c1.second, c2.first, c2.second);
    double intercept = bisectlines.yIntercept(c1.first, c1.second, slope);
    bool check = bisectlines.validateBisectingPoint(
        vp, slope, intercept
    );  
    std::cout << check << std::endl;
    return 0;
}

// https://chat.openai.com/share/ef43db05-947a-4f26-b76c-a2abbb9aeb4b