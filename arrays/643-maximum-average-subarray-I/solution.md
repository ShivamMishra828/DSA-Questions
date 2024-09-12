# Maximum Average Subarray I (Question 643)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/maximum-average-subarray-i/)

You are given an integer array `nums` consisting of `n` elements, and an integer `k`. You need to find the contiguous subarray of length `k` that has the maximum average and return this value.

### Constraints

-   1 ≤ k ≤ nums.length ≤ 10^5
-   -10^4 ≤ nums[i] ≤ 10^4

## Solution

```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = 0;   // Variable to store the maximum sum of subarray of length k
        double sum = 0;   // Variable to store the current sum of the sliding window

        // Calculate the sum of the first k elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        ans = sum;   // Initialize ans to the sum of the first k elements

        // Use a sliding window approach to find the maximum sum of a subarray of length k
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i];        // Add the next element to the window
            sum -= nums[i - k];    // Remove the element that is out of the window
            ans = max(ans, sum);   // Update the maximum sum
        }

        // Return the maximum average
        return ans / k;
    }
};
```

## Explanation

-   The algorithm uses the sliding window technique to find the maximum sum of any subarray of length k.
-   We first compute the sum of the first k elements and store it in the sum variable.
-   We then slide the window one element at a time: for each new element added to the window, we remove the first element of the previous window from the sum.
-   At each step, we update the ans variable to store the maximum sum encountered so far.
-   Finally, we return the maximum sum divided by k to get the maximum average.

### Important Concepts

-   Sliding window technique: This allows us to compute the sum of the subarrays in O(1) time after the initial sum of the first subarray, making the algorithm more efficient.
-   Efficient handling of large arrays by avoiding recomputation of sums from scratch for each subarray.

## Notes

This approach ensures that the maximum average is found in O(n) time, making it suitable for large arrays.

### Time Complexity

O(n), where n is the number of elements in the array. We traverse the array once to compute the sum of subarrays.

### Space Complexity

O(1), as we use only a constant amount of extra space for the variables.

### Edge Cases

-   The input array contains negative numbers.
-   The array length is exactly equal to k.
-   All elements in the array are the same.
