# Missing Number (Question 268)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/missing-number/)

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

### Constraints

-   The length of the array is `n`
-   1 ≤ n ≤ 10^4
-   0 ≤ nums[i] ≤ n
-   All the numbers in the array are unique.

## Solution

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        return total - sum;
    }
};
```

## Explanation

-   The total sum of numbers from 0 to n is calculated using the formula n \* (n + 1) / 2.
-   We calculate the sum of the elements in the given array nums.
-   The missing number is found by subtracting the sum of the array from the total sum.

### Important Concepts

-   Mathematical summation formula for the first n natural numbers.
-   This approach ensures we find the missing number in O(n) time.

### Notes

-   This solution efficiently computes the missing number in a single pass through the array.
-   The use of the summation formula eliminates the need for sorting or additional space.

### Time Complexity

O(n), where n is the length of the array.

### Space Complexity

O(1), as no extra space is used except for a few variables.

### Edge Cases

-   Array is missing the first number (0).
-   Array is missing the last number (n).
-   Small array sizes (e.g., n = 1).
