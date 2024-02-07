class Solution
{
public:
    // Check if the array contains a cycle that meets certain criteria
    bool circularArrayLoop(vector<int> &nums)
    {
        int n = nums.size(); // Get the size of the array
        // Iterate over the array to find a cycle
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 0)
                continue; // Skip elements that are already marked as 0 (visited)

            // Use two pointers: 'slow' and 'fast' to detect cycles
            int slow = i;
            int fast = getNextIndex(nums, i);

            // Keep advancing 'slow' by one step and 'fast' by two steps
            // Continue looping as long as the direction (sign) of the numbers is the same
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[getNextIndex(nums, fast)] > 0)
            {
                if (slow == fast)
                {
                    // Cycle is found, check if it's longer than one element
                    if (slow != getNextIndex(nums, slow))
                    {
                        return true;
                    }
                    // If not, break and move on to next element in the array
                    break;
                }
                // Move 'slow' one step forward
                slow = getNextIndex(nums, slow);
                // Move 'fast' two steps forward
                fast = getNextIndex(nums, getNextIndex(nums, fast));
            }

            // Mark all visited elements in the cycle as 0
            int j = i;
            while (nums[j] * nums[getNextIndex(nums, j)] > 0)
            {
                int nextIndex = getNextIndex(nums, j);
                nums[j] = 0;
                j = nextIndex;
            }
        }

        // Return false if no qualifying cycle is found
        return false;
    }

    // Helper function to get the next index in the circular array
    int getNextIndex(vector<int> &nums, int i)
    {
        int n = nums.size();
        // Calculate the next index accounting for wrapping around the array
        return ((i + nums[i]) % n + n) % n; // The double modulo ensures a positive result
    }
};