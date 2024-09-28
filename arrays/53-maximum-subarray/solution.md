# Maximum Subarray (Question 53)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/maximum-subarray/)

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

### Constraints

-   1 ≤ `nums.length` ≤ 10^5
-   `-10^4 ≤ nums[i] ≤ 10^4`

## Solution

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int currSum = 0;  // Keeps track of the current subarray sum
        int maxSum = Integer.MIN_VALUE;  // Stores the maximum subarray sum found so far

        // Edge case: if there's only one element, return it as the max sum
        if(nums.length == 1) {
            return nums[0];
        }

        // Traverse the array to find the maximum subarray sum
        for(int i = 0; i < nums.length; i++) {
            currSum += nums[i];  // Add the current element to the current sum

            // Update maxSum if currSum is greater than maxSum
            if(maxSum < currSum) {
                maxSum = currSum;
            }

            // Reset currSum if it drops below or equals 0
            if(currSum <= 0) {
                currSum = 0;
            }
        }

        return maxSum;  // Return the maximum sum found
    }
}
```

## Explanation

1. Initialize variables:

    - currSum: Tracks the sum of the current subarray.
    - maxSum: Keeps track of the maximum sum encountered so far. Initially set to the smallest possible integer value.

2. Iterate through the array:

    - For each element in the array, add it to currSum.
    - Update maxSum if currSum is greater than maxSum.
    - If currSum becomes zero or negative, reset it to 0 to start a new subarray.

3. Edge Case:

    - If the array has only one element, that element is the maximum subarray sum.

### Important Concepts

    Kadane's Algorithm: This approach allows us to find the maximum subarray sum in a single pass by maintaining the sum of the current subarray and updating the maximum sum accordingly.

### Dry Run

Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4]

1. Initial State: currSum = 0, maxSum = Integer.MIN_VALUE.

2. Step 1:

    - i = 0, nums[0] = -2, currSum = 0 + (-2) = -2.
    - Update maxSum: maxSum = max(-2, -∞) = -2.
    - Reset currSum: currSum = 0 (because it's less than 0).

3. Step 2:

    - i = 1, nums[1] = 1, currSum = 0 + 1 = 1.
    - Update maxSum: maxSum = max(1, -2) = 1.

4. Step 3:

    - i = 2, nums[2] = -3, currSum = 1 + (-3) = -2.
    - No change to maxSum.
    - Reset currSum = 0.

5. Continue this process until all elements are processed.

Final Output: The maximum subarray sum is 6 (subarray [4, -1, 2, 1]).

### Time Complexity

O(n): We traverse the array once, where n is the number of elements in the array.

### Space Complexity

O(1): The algorithm uses constant extra space.

### Edge Cases

-   The array contains only one element.
-   All elements are negative.
-   The array contains both positive and negative numbers, testing the effectiveness of resetting currSum.
