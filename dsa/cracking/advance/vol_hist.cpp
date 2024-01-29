// 21. **Volume of Histogram:** Imagine a histogram (bar graph). Design an algorithm to compute the volume of water it could hold if someone poured water across the top. You can assume that each histogram bar has width 1.

// Example: (Black bars are the histogram. Gray is water.)<br>
// Input: {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0}

// [Image](/leetcode/assets/adv21.png)
// <br>
// Output: 26
#include <iostream>
#include <vector>

using namespace std;

int calculateWaterVolume(const vector<int> &histogram)
{
    int n = histogram.size();
    if (n <= 2)
        return 0;

    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);

    leftMax[0] = histogram[0];
    for (int i = 1; i < n; ++i)
        leftMax[i] = max(leftMax[i - 1], histogram[i]);

    rightMax[n - 1] = histogram[n - 1];
    for (int i = n - 2; i >= 0; --i)
        rightMax[i] = max(rightMax[i + 1], histogram[i]);

    int waterVolume = 0;
    for (int i = 0; i < n; ++i)
    {
        int minHeight = min(leftMax[i], rightMax[i]);
        waterVolume += max(0, minHeight - histogram[i]);
    }

    return waterVolume;
}

int main()
{
    vector<int> histogram = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
    int result = calculateWaterVolume(histogram);

    cout << "Water volume: " << result << endl;

    return 0;
}

// https://chat.openai.com/share/6ab60455-059e-4ef1-b086-60cc564482c0