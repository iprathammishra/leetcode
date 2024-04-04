from collections import Counter
from collections import defaultdict
from itertools import combinations, groupby
from typing import List
import numpy as np
from numpy import inf
import sys
import heapq


class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        left, right = 0, len(height) - 1
        leftMax, rightMax = height[left], height[right]
        res = 0
        while left < right:
            if leftMax < rightMax:
                left += 1
                leftMax = max(leftMax, height[left])
                res += leftMax - height[left]
            else:
                right -= 1
                rightMax = max(rightMax, height[right])
                res += rightMax - height[right]
        return res


if __name__ == "__main__":
    sol = Solution()
    print(
        sol.trap(
            height=[4, 2, 0, 3, 2, 5]
        ),
    )
