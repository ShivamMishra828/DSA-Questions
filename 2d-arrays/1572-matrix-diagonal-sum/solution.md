# Matrix Diagonal Sum (Question 1572)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/matrix-diagonal-sum/)

Given a square matrix `mat`, return the sum of the matrix diagonals. Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

### Constraints

-   `n == mat.length == mat[i].length`
-   1 ≤ n ≤ 100
-   `-1000 ≤ mat[i][j] ≤ 1000`

## Solution

```java
class Solution {
    public int diagonalSum(int[][] mat) {
        // Initialize the sum variable to store the sum of diagonal elements
        int sum = 0;

        // Traverse through each row and column
        for(int i = 0; i < mat.length; i++) {
            // Add the primary diagonal element mat[i][i]
            sum += mat[i][i];

            // Check if it's not the same element as in the primary diagonal to avoid double counting
            if(i != mat.length - i - 1) {
                // Add the secondary diagonal element mat[i][mat.length - i - 1]
                sum += mat[i][mat.length - i - 1];
            }
        }

        // Return the sum of diagonal elements
        return sum;
    }
}
```

## Explanation

-   Primary diagonal: Elements where the row index equals the column index (i == j).
-   Secondary diagonal: Elements where the sum of row and column indices equals n - 1 (i + j == n - 1).
-   In the loop, we directly sum up both primary and secondary diagonal elements. We use the condition i != mat.length - i - 1 to ensure we don't double-count the center element when the matrix size is odd.

### Time Complexity

O(n): We iterate through the matrix once, where n is the size of the matrix (since it's a square matrix).

### Space Complexity

O(1): No additional space is used apart from the sum variable.

### Edge Cases

-   If the matrix has only one element, the function will return that element directly.
-   If the matrix size is odd, the center element will only be counted once, even though it lies on both diagonals.

### Dry Run

Input mat = [
[1, 2, 3],
[4, 5, 6],
[7, 8, 9]
]

Execution Steps

1. Initial Setup:
   sum = 0
2. First Iteration (i = 0):

-   Primary diagonal element: mat[0][0] = 1 (add to sum)
    -   sum = 1
-   Secondary diagonal element: mat[0][2] = 3 (add to sum)
    -   sum = 4

3. Second Iteration (i = 1):

-   Primary diagonal element: mat[1][1] = 5 (add to sum)
    -   sum = 9
-   Secondary diagonal element: No addition because the center element is already added from the primary diagonal.

4. Third Iteration (i = 2):

-   Primary diagonal element: mat[2][2] = 9 (add to sum)
    -   sum = 18
-   Secondary diagonal element: mat[2][0] = 7 (add to sum)
    -   sum = 25

Final Output:- 25
