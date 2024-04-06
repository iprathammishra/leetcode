from collections import Counter
from collections import defaultdict
from itertools import combinations, groupby
from typing import List
import numpy as np
from numpy import inf
import sys
import heapq


class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        toDelStack = []
        for index, char in enumerate(s):
            if char == '(':
                stack.append([index, char])
            elif char == ')' and not stack:
                toDelStack.append(index)
            elif char == ')':
                stack.pop()
        if stack:
            for i, c in stack:
                toDelStack.append(i)
        characters = list(s)
        for toDel in toDelStack:
            characters[toDel] = '0'
        res = [ch for ch in characters if ch != '0']
        return "".join(res)


if __name__ == "__main__":
    sol = Solution()
    print(
        sol.minRemoveToMakeValid(
            s="()"
        ),
    )
