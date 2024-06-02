class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        
        meetings.sort()
        days_cnt = 0
        mx = float("-inf")

        for i in range(len(meetings)):
            if mx >= meetings[i][1]:
                continue
            else:
                if meetings[i][0] > mx:
                    days_cnt += (meetings[i][1] - meetings[i][0] + 1)
                else:
                    days_cnt += (meetings[i][1] - mx)
            mx = max(mx, meetings[i][1])

        return days - days_cnt
            