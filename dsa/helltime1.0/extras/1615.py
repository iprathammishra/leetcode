class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        dx=[0]*n
        for s,t in roads:
            dx[s]+=1
            dx[t]+=1
        cnt=[]
        for i in range(n):
            for j in range(i+1,n):
                if [i,j] in roads or [j,i] in roads:
                    cnt.append(dx[i]+dx[j]-1)
                else:
                    cnt.append(dx[i]+dx[j])
        return max(cnt)