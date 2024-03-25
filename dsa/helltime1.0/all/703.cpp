class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<>> min_heap;
    int kthSize;
    KthLargest(int k, vector<int> &nums)
    {
        kthSize = k;
        for (const int it : nums)
        {
            add(it);
        }
    }

    int add(int val)
    {
        min_heap.push(val);
        if (min_heap.size() > kthSize)
        {
            min_heap.pop();
        }
        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */