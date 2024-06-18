class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        
        jobs = [(difficulty[i], profit[i]) for i in range(len(difficulty))]

        worker.sort()
        jobs.sort()

        profit, mx_profit, idx = 0, 0, 0
        for work in worker:
            while idx < len(difficulty) and work >= jobs[idx][0]:
                mx_profit = max(mx_profit, jobs[idx][1])
                idx += 1
            profit += mx_profit
        
        return profit
