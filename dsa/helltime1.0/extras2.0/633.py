class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        
        left, right = 0, int(c**0.5)
        while left <= right:
            if left*left + right*right == c:
                return True
            elif left*left + right*right > c:
                right -= 1
            else:
                left -= 1
            
        return False
