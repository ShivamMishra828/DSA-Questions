# Sqrt(x) (Question 69)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/sqrtx/)

Given a non-negative integer `x`, compute and return the square root of `x`. Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

### Constraints

-   0 ≤ x ≤ 2^31 - 1

## Solution

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int s = 0; // Start of the range
        int e = x; // End of the range (max possible square root is x)
        long long mid = s + (e - s) / 2; // Calculate mid-point
        int ans = 0; // Variable to store the final answer

        // Perform binary search to find the square root
        while (s <= e) {
            // If mid * mid equals x, we found the square root
            if (mid * mid == x) {
                return mid;
            }
            // If mid * mid is less than x, move to the right half
            else if (mid * mid < x) {
                ans = mid; // Store the potential answer (as integer part)
                s = mid + 1; // Move to the right half
            }
            // If mid * mid is greater than x, move to the left half
            else {
                e = mid - 1; // Move to the left half
            }

            // Recalculate mid for the next iteration
            mid = s + (e - s) / 2;
        }
        return ans; // Return the truncated integer square root
    }
};
```

## Explanation

-   The problem requires finding the integer square root of x. The most efficient way is to use binary search.
-   We initialize the search range from 0 to x. The mid value is recalculated at each step.
-   If mid \* mid == x, then mid is the exact square root, and we return it.
-   If mid \* mid < x, it means the square root lies on the right half of the search range, so we move the start pointer to mid + 1. We also update the ans variable with mid because it could be the integer part of the square root.
-   If mid \* mid > x, it means the square root lies on the left half, so we move the end pointer to mid - 1.
-   The loop continues until the start index exceeds the end index, and the integer square root is returned.

### Important Concepts

-   Binary Search: We use binary search to efficiently find the square root in logarithmic time.
-   Integer Square Root: The result is truncated to the integer part, as required by the problem.

## Notes

-   We use long long for mid to handle cases where mid \* mid may exceed the range of int.
-   The function handles edge cases like x = 0 and x = 1, where the square root is the number itself.

### Time Complexity

O(log x), because we are reducing the search space by half at each step using binary search.

### Space Complexity

O(1), as we are using a constant amount of extra space.

### Edge Cases

-   x = 0: The result is 0 because the square root of 0 is 0.
-   x = 1: The result is 1 because the square root of 1 is 1.
-   Very large values of x (close to the upper limit of 2^31 - 1).
