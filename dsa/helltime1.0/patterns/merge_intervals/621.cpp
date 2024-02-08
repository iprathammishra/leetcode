class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> taskCount(26);
        int maxCount = 0;
        for (char task : tasks) {
            task -= 'A';
            taskCount[task]++;
            maxCount = max(maxCount, taskCount[task]);
        }
        int frequencyMaxCountTask = 0;
        for (const int &i : taskCount)
            if (i == maxCount)
                frequencyMaxCountTask++;
        int minTimeSlot = (maxCount - 1) * (n + 1) + frequencyMaxCountTask;
        return max(static_cast<int>(tasks.size()), minTimeSlot);
    }
};
