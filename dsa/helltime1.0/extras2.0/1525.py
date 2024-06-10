class Solution:
    def numSplits(self, s: str) -> int:

        def preprocess(x):
            visited = set()
            cnt = 0
            array = []
            for ch in x:
                if ch not in visited:
                    cnt += 1
                    visited.add(ch)
                array.append(cnt)
            
            return array

        left_array = preprocess(s)
        right_array = preprocess(list(s)[::-1])

        right_array = right_array[::-1]
        res = 0
        for i in range(len(left_array) - 1):
            if left_array[i] == right_array[i+1]:
                res += 1
        
        return res 
