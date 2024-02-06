# When to use Two Pointers.

The two-pointer method is a popular algorithmic technique used to solve problems that involve iterating through a sequence or array with two pointers or references. It's a simple and efficient approach that is often employed to optimize the time complexity of an algorithm. Here are some common scenarios where you might want to use the two-pointer method in C++:

1. Searching In a Sorted Array/List:

Given a sorted array or list, you can us the two pointers to efficiently find a pair of elements, or a specific target value. Initialize one pointer at the beginning and another at the end. Adjust the pointers based on the comparison of the sum or difference with the target value.

```cpp
bool twoSumSorted(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return true; // Pair found
        } else if (sum < target) {
            left++; // Move left pointer to increase the sum
        } else {
            right--; // Move right pointer to decrease the sum
        }
    }

    return false; // Pair not found
}
```

2. Palindrome Checking:

You can use two pointers to check if a string is a palindrome by comparing characters from the start and end, moving towards the center.

```cpp
bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false; // Not a palindrome
        }
        left++;
        right--;
    }

    return true; // Palindrome
}
```

3. Merging Two Sorted Lists/Arrays:

Merge two sorted arrays or lists in-place using two pointers, starting from the end to avoid overwriting elements.

```cpp
void mergeSortedArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}
```
