class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        points.sort(key=lambda point:point[0], reverse=True)
        cr=0
        mx=cr
        for i in range(len(points)-1):
            cr=points[i][0]-points[i+1][0]
            mx=max(mx,cr)
        return mx