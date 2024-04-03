from collections import Counter
from collections import defaultdict
from itertools import combinations
from typing import List
import numpy as np


class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        string1split = s1.split()
        string2split = s2.split()
        count1 = Counter(string1split)
        count2 = Counter(string2split)
        res = []
        for s in string1split:
            if s not in string2split and count1[s] == 1:
                res.append(s)
        for s in string2split:
            if s not in string1split and count2[s] == 1:
                res.append(s)
        return res


if __name__ == "__main__":
    sol = Solution()
    print(
        sol.uncommonFromSentences(
            s1="this apple is sweet", s2="this apple is sour")
    )
