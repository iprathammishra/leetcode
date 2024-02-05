class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        priority_queue<int, vector<int>, less<int>> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (const int &i : nums1)
        {
            if (maxHeap.empty() || i <= maxHeap.top())
                maxHeap.push(i);
            else
                minHeap.push(i);
            
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
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        else
            return maxHeap.top();
    }
};