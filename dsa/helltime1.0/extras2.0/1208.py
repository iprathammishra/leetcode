def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
    arr = []
    n = len(s)
    for i in range(n):
        arr.append(abs(ord(s[i]) - ord(t[i])))

    start = 0
    end = 0
    curr = 0
    res = 0
    while start <= end and end < n:
        curr += arr[end]
        if curr > maxCost:
            curr -= arr[start]
            start += 1

        res = max(res, end - start + 1)
        end += 1

    return res
