# Clumsy Factorial (Question 1006)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/clumsy-factorial/)

The clumsy factorial of a number `n` is computed by applying the following cyclic operations: multiplication (`*`), division (`/`), addition (`+`), and subtraction (`-`), in that order, starting from `n` and decreasing sequentially. For example, for `n = 10`, the clumsy factorial is: 10 _ 9 / 8 + 7 - 6 _ 5 / 4 + 3 - 2 \* 1.

Given an integer `n`, return the clumsy factorial of `n`.

### Constraints

-   1 ≤ n ≤ 10,000

## Solution

```cpp
class Solution {
public:
    int clumsy(int n) {
        // Handle small values of n directly with special cases.
        if (n == 1 || n == 2) return n;  // n=1 or n=2 results in the same number.
        if (n == 3) return 6;  // For n=3, 3 * 2 * 1 = 6.
        if (n == 4) return 7;  // For n=4, 4 * 3 / 2 + 1 = 7.

        // General case: The result varies based on the remainder when n is divided by 4.
        if (n % 4 == 0) return n + 1;  // When n is divisible by 4, the pattern results in n + 1.
        if (n % 4 == 1 || n % 4 == 2) return n + 2;  // For n mod 4 = 1 or 2, the result is n + 2.
        if (n % 4 == 3) return n - 1;  // When n mod 4 = 3, the result is n - 1.

        return 0;  // This line is never reached but added for completeness.
    }
};
```

## Explanation

Handling Base Cases:

-   For n = 1 or n = 2, return the value of n itself since the cyclic operations don't have much impact.
-   For n = 3, the result of 3 _ 2 _ 1 is 6.
-   For n = 4, the calculation yields 4 \* 3 / 2 + 1 = 7.

### General Case:

-   For values of n greater than 4, the result depends on the remainder when n is divided by 4:
-   If n % 4 == 0, the result follows a pattern of n + 1.
-   If n % 4 == 1 or n % 4 == 2, the result becomes n + 2.
-   If n % 4 == 3, the result is n - 1.

### Optimized Solution:

Instead of simulating all operations for large n, recognizing these patterns reduces the problem to simple arithmetic operations, making the solution efficient even for large values of n.

### Time Complexity

O(1) – The solution uses constant time for any input size by recognizing the patterns in the cyclic operations.

### Space Complexity

O(1) – The solution only uses a fixed amount of space.
