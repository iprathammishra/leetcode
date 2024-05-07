import numpy as np
class Solution:
    def isStrictlyPalindromic(self, n: int) -> bool:
        for i in range(2,n-1):
            if np.base_repr(n,i)!=np.base_repr(n,i)[::-1]:
                return False
        return True