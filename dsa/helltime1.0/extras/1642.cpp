class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i = 0; i < heights.size() - 1; ++i)
        {
            if (heights[i + 1] > heights[i])
            {
                min_heap.push(heights[i + 1] - heights[i]);
                if (min_heap.size() > ladders)
                {
                    bricks = bricks - min_heap.top();
                    min_heap.pop();
                    if (bricks < 0)
                    {
                        return i;
                    }
                }
            }
        }
        return heights.size() - 1;
    }
};