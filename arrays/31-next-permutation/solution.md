# 31. Next Permutation

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/next-permutation/)

Given an array of integers `nums`, rearrange the array into the lexicographically next greater permutation of numbers. If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

You must modify the input array in place and use only constant extra memory.

### Solution

```java
class Solution {
    public void nextPermutation(int[] nums) {
        // Step 1: Find the largest index `i` such that nums[i] < nums[i + 1]
        int i = nums.length - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--; // Move backwards until we find the first decreasing element
        }

        // Step 2: If such an index exists, find the largest index `j` such that nums[j] > nums[i]
        if (i != -1) {
            int j = nums.length - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--; // Find the smallest element greater than nums[i]
            }
            // Step 3: Swap elements at `i` and `j`
            swap(nums, i, j);
        }

        // Step 4: Reverse the sequence from `i + 1` to the end of the array
        int start = i + 1;
        int end = nums.length - 1;
        while (start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
    }

    // Helper method to swap two elements in an array
    public static void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
```

## Explanation

Step-by-Step Breakdown:

1. Find the first decreasing element (i):

-   Start from the second last element of the array and move backward to find the first element that is smaller than the one next to it.
-   If such an element is found, store its index i. If no such element is found, i becomes -1, meaning the array is in descending order.

2. Find the smallest element greater than nums[i] (j):

-   If i is not -1, find the smallest element from the right that is larger than nums[i]. This ensures we get the next lexicographical order.

3. Swap the elements at index i and j:

-   Swap nums[i] with nums[j] to get closer to the next permutation.

4. Reverse the array from index i + 1:

-   After the swap, the sequence after i is still in descending order, so reverse the part of the array starting from i + 1 to the end to get the smallest possible permutation for this portion.

### Time Complexity

O(n): We iterate over the array a few times, once to find the first decreasing element, once to find the next largest element, and once to reverse a portion of the array.

### Space Complexity

O(1): The solution uses constant extra space as it modifies the array in place.

### Dry Run

Input: nums = [1, 2, 3]
Execution Steps

1. Find i:

-   Start from index 1 (nums[1] = 2), nums[1] < nums[2] (2 < 3), so i = 1.

2. Find j:

-   Start from the end, find j such that nums[1] < nums[2] (2 < 3), so j = 2.

3. Swap i and j:

-   Swap nums[1] and nums[2], so nums = [1, 3, 2].

4. Reverse the array from i + 1:

-   Since the portion after i + 1 is already in ascending order, no changes are needed.

Output:- [1, 3, 2]
In this case, the next permutation of [1, 2, 3] is [1, 3, 2].

Edge Case
If the array is in descending order like [3, 2, 1], the algorithm will return the smallest permutation, which is [1, 2, 3].
