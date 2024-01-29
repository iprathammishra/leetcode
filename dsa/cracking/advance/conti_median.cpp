// 20. **Continuous Median:** Numbers are randomly generated and passed to a method. Write a program to find and maintain the median value as new values are generated.
#include <iostream>
#include <queue>
#include <vector>
class ContinuousMedian
{
private:
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;    // stores the smaller half
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // stores the larger half
public:
    void insertNumber(int num)
    {
        if (maxHeap.empty() || num <= maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);

        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double getMedian() const
    {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        else
            return maxHeap.top();
    }
};
int main()
{
    ContinuousMedian continuousMedian;

    continuousMedian.insertNumber(5);
    std::cout << "Median: " << continuousMedian.getMedian() << std::endl;

    continuousMedian.insertNumber(10);
    std::cout << "Median: " << continuousMedian.getMedian() << std::endl;

    continuousMedian.insertNumber(15);
    std::cout << "Median: " << continuousMedian.getMedian() << std::endl;

    continuousMedian.insertNumber(3);
    std::cout << "Median: " << continuousMedian.getMedian() << std::endl;

    return 0;
}

// https://chat.openai.com/share/59ce0ac0-1f3c-4ed9-a5b5-3ad19fbaeb62