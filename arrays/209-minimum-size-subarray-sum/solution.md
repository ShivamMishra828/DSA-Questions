# Minimum Size Subarray Sum (Question 209)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/minimum-size-subarray-sum/)

Given an array of positive integers `nums` and a positive integer `target`, return the minimal length of a **contiguous subarray** of which the sum is greater than or equal to `target`. If there is no such subarray, return `0` instead.

### Constraints

-   1 ≤ `target` ≤ 10^9
-   1 ≤ `nums.length` ≤ 10^5
-   1 ≤ `nums[i]` ≤ 10^4

## Solution

```java
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        int currSum = 0;  // Variable to track the current sum of the subarray
        int l = 0, r = 0;  // Two pointers: l for the left and r for the right of the sliding window
        int ans = Integer.MAX_VALUE;  // Variable to track the minimal length of the subarray

        // Traverse the array using a sliding window technique
        while(r < n) {
            currSum += nums[r];  // Add the current element to the running sum

            // Shrink the window if the current sum is greater than or equal to the target
            while(currSum >= target) {
                // Update the answer with the minimal length found
                ans = Math.min(r - l + 1, ans);
                currSum -= nums[l];  // Remove the leftmost element from the sum
                l++;  // Move the left pointer to shrink the window
            }

            r++;  // Move the right pointer to explore the next element
        }

        // If no valid subarray was found, return 0. Otherwise, return the minimal length.
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }
}
```

## Explanation

-   Sliding Window Technique:

    -   We use two pointers (l for left and r for right) to represent the window.
    -   Initially, both pointers are set to 0. We move r to the right and keep adding nums[r] to the currSum.
    -   When currSum becomes greater than or equal to the target, we try to shrink the window from the left (l pointer) to see if we can still meet the target with a smaller subarray.

-   Time Complexity:

    -   Each element is added and removed from the sum at most once, resulting in O(n) time complexity.

-   Edge Case:

    -   If no subarray meets the condition (sum >= target), the answer should be 0.

### Dry Run

Input: target = 7, nums = [2, 3, 1, 2, 4, 3]

1.  Initial State: currSum = 0, l = 0, r = 0, ans = Integer.MAX_VALUE

2.  Step 1:

    -   nums[r] = 2, currSum = 2, r = 1
    -   currSum is less than target. Continue.

3.  Step 2:

    -   nums[r] = 3, currSum = 5, r = 2
    -   currSum is less than target. Continue.

4.  Step 3:

    -   nums[r] = 1, currSum = 6, r = 3
    -   currSum is less than target. Continue.

5.  Step 4:

    -   nums[r] = 2, currSum = 8, r = 4
    -   currSum is now greater than or equal to target.
    -   Update ans = min(4 - 0 + 1, Integer.MAX_VALUE) = 4.
    -   Shrink the window: currSum = 6, l = 1.

6.  Step 5:

    -   nums[r] = 4, currSum = 10, r = 5
    -   Shrink the window again: currSum = 7, l = 2
    -   Update ans = min(5 - 2 + 1, 4) = 3.
    -   Shrink further: currSum = 4, l = 3.

7.  Step 6:

    -   Continue shrinking and checking until r reaches the end.

    Final Answer: The minimal length of the subarray is 2 (subarray [4, 3]).

### Edge Cases

-   The array has only one element greater than or equal to the target.
-   The sum of all elements is still less than the target.
-   The array is empty or doesn't have a subarray that meets the condition.
