from collections import Counter
from collections import defaultdict


def algo(nums, k):
    count = defaultdict(int)
    l_far = 0
    l_near = 0
    res = 0
    for r in range(len(nums)):
        count[nums[r]] += 1
        while len(count) > k:
            count[nums[l_near]] -= 1
            if count[nums[l_near]] == 0:
                count.pop(nums[l_near])
            l_near += 1
            l_far = l_near
        while count[nums[l_near]] > 1:
            count[nums[l_near]] -= 1
            l_near += 1
        if len(count) == k:
            res += l_near - l_far + 1
    return res


if __name__ == "__main__":
    nums = [1, 2, 1, 2, 3]
    k = 2
    print(algo(nums, k))
