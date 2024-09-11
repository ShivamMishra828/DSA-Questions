# Find Pivot Index (Question 724)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/find-pivot-index/)

Given an array of integers `nums`, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers to the left of the index is equal to the sum of all the numbers to the right of the index.

If no such index exists, return `-1`. If there are multiple pivot indexes, you should return the left-most pivot index.

### Constraints

-   1 ≤ nums.length ≤ 10^4
-   -1000 ≤ nums[i] ≤ 1000

## Solution

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int lsum = 0;
        int rsum = 0;
        int totalSum = 0;

        // Calculate total sum of the array
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        // Iterate through the array to find pivot index
        for (int i = 0; i < nums.size(); i++) {
            rsum = totalSum - lsum - nums[i];  // Calculate right sum
            if (lsum == rsum) {
                return i;  // Pivot index found
            } else {
                lsum += nums[i];  // Add current element to left sum
            }
        }

        return -1;  // Return -1 if no pivot index is found
    }
};
```

## Explanation

-   First, we calculate the total sum of all the elements in the array.
-   We iterate through the array and, for each element, calculate the right sum as totalSum - lsum - nums[i].
-   If at any point lsum equals rsum, we return the current index as the pivot index.
-   If no such index is found, we return -1.

### Important Concepts

-   Left and right cumulative sum calculation.
-   Efficient use of the total sum to avoid recalculating the right sum in each iteration.

## Notes

-   This approach calculates the total sum in advance, reducing the need for nested loops.
-   The left sum and right sum are compared for each element to find the pivot.

### Time Complexity

O(n), where n is the length of the array.

### Space Complexity

O(1), as we only use a constant amount of space for the sum variables.

### Edge Cases

-   Array with all zeros.
-   Array where the pivot is the first or last element.
-   Negative numbers in the array.
