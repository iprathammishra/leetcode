# Backtracking for Beginners

- Combination Sum

```python
    def combinationSum(self, candidates, target):
        def backtrack(tmp, start, end, target):
            if target == 0:
                ans.append(tmp[:])
            elif target > 0:
                for i in range(start, end):
                    tmp.append(candidates[i])
                    backtrack(tmp, i, end, target - candidates[i])
                    tmp.pop()
        ans = []
        candidates.sort(reverse= True)
        backtrack([], 0, len(candidates), target)
        return ans
```

- Combination Sum II

```python
    def combinationSum2(self, candidates, target):
        def backtrack(start, end, tmp, target):
            if target == 0:
                ans.append(tmp[:])
            elif target > 0:
                for i in range(start, end):
                    if i > start and candidates[i] == candidates[i-1]:
                        continue
                    tmp.append(candidates[i])
                    backtrack(i+1, end, tmp, target - candidates[i])
                    tmp.pop()
        ans = []
        candidates.sort(reverse= True)
        backtrack(0, len(candidates), [], target)
        return ans
```

- Subsets

```python
    def subsets(self, nums):
        def backtrack(start, end, tmp):
            ans.append(tmp[:])
            for i in range(start, end):
                tmp.append(nums[i])
                backtrack(i+1, end, tmp)
                tmp.pop()
        ans = []
        backtrack(0, len(nums), [])
        return ans
```

- Subsets II

```python
    def subsetsWithDup(self, nums):
        def backtrack(start, end, tmp):
            ans.append(tmp[:])
            for i in range(start, end):
                if i > start and nums[i] == nums[i-1]:
                    continue
                tmp.append(nums[i])
                backtrack(i+1, end, tmp)
                tmp.pop()
        ans = []
        nums.sort()
        backtrack(0, len(nums), [])
        return ans
```

- Permutations

```python
    def permute(self, nums):
        def backtrack(start, end):
            if start == end:
                ans.append(nums[:])
            for i in range(start, end):
                nums[start], nums[i] = nums[i], nums[start]
                backtrack(start+1, end)
                nums[start], nums[i] = nums[i], nums[start]

        ans = []
        backtrack(0, len(nums))
        return ans
```

- Permutations II

```python
    def permuteUnique(self, nums):
        def backtrack(tmp, size):
            if len(tmp) == size:
                ans.append(tmp[:])
            else:
                for i in range(size):
                    if visited[i] or (i > 0 and nums[i-1] == nums[i] and not visited[i-1]):
                        continue
                    visited[i] = True
                    tmp.append(nums[i])
                    backtrack(tmp, size)
                    tmp.pop()
                    visited[i] = False
        ans = []
        visited = [False] * len(nums)
        nums.sort()
        backtrack([], len(nums))
        return ans
```

- Permutation Sequence

```python
    def getPermutation(self, n, k):
        nums = [str(i) for i in range(1, n+1)]
        fact = [1] * n
        for i in range(1,n):
            fact[i] = i*fact[i-1]
        k -= 1
        ans = []
        for i in range(n, 0, -1):
            id = k / fact[i-1]
            k %= fact[i-1]
            ans.append(nums[id])
            nums.pop(id)
        return ''.join(ans)
```

- Palindrome Partitioning

```python
    def partition(self, s):
        def backtrack(start, end, tmp):
            if start == end:
                ans.append(tmp[:])
            for i in range(start, end):
                cur = s[start:i+1]
                if cur == cur[::-1]:
                    tmp.append(cur)
                    backtrack(i+1, end, tmp)
                    tmp.pop()
        ans = []
        backtrack(0, len(s), [])
        return ans
```

- Palindrome Permutation II. Related to: Next Permutation / Palindrome Permutation

```python
    def generatePalindromes(self, s):
        kv = collections.Counter(s)
        mid = [k for k, v in kv.iteritems() if v%2]
        if len(mid) > 1:
            return []
        mid = '' if mid == [] else mid[0]
        half = ''.join([k * (v/2) for k, v in kv.iteritems()])
        half = [c for c in half]

        def backtrack(end, tmp):
            if len(tmp) == end:
                cur = ''.join(tmp)
                ans.append(cur + mid + cur[::-1])
            else:
                for i in range(end):
                    if visited[i] or (i>0 and half[i] == half[i-1] and not visited[i-1]):
                        continue
                    visited[i] = True
                    tmp.append(half[i])
                    backtrack(end, tmp)
                    visited[i] = False
                    tmp.pop()

        ans = []
        visited = [False] * len(half)
        backtrack(len(half), [])
        return ans
```
