# Transpose Matrix (Question 867)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/transpose-matrix/)

Given a 2D integer matrix `matrix`, return the **transpose** of `matrix`.

The **transpose** of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

### Constraints

-   `m == matrix.length`
-   `n == matrix[i].length`
-   `1 <= m, n <= 1000`
-   `1 <= matrix[i][j] <= 10^9`

## Solution

```java
class Solution {
    public int[][] transpose(int[][] matrix) {
        // Get dimensions of the original matrix
        int rows = matrix.length;
        int cols = matrix[0].length;

        // Initialize the result matrix with dimensions flipped (rows become columns and vice versa)
        int ans[][] = new int[cols][rows];

        // Fill the transposed matrix by switching rows with columns
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                ans[j][i] = matrix[i][j];
            }
        }

        // Return the transposed matrix
        return ans;
    }
}
```

## Explanation

-   We are given a matrix with m rows and n columns.
-   To transpose the matrix, we need to flip the rows and columns such that the element at position (i, j) in the original matrix moves to position (j, i) in the transposed matrix.
-   We create a new matrix ans of dimensions n x m where rows and columns are swapped, and we iterate through the original matrix to populate the transposed matrix.

### Important Concepts

-   Transpose of a matrix: The transpose of a matrix is formed by swapping rows with columns.
-   For example, if the original matrix is: [[1, 2, 3], [4, 5, 6]]
-   The transposed matrix will be: [[1, 4], [2, 5], [3, 6]]

### Time Complexity

O(m \* n): We are iterating through all elements of the matrix where m is the number of rows and n is the number of columns.

### Space Complexity

O(m \* n): We are creating a new matrix of size n x m to store the transposed result.

### Dry Run

Input:- matrix = [
[1, 2, 3],
[4, 5, 6]
]

Execution Steps

1. Initial Setup:

-   rows = 2, cols = 3
-   Create an empty result matrix ans of size 3 x 2.

2. First Row Transposition:

-   For i = 0 and j = 0, ans[0][0] = matrix[0][0] = 1.
-   For i = 0 and j = 1, ans[1][0] = matrix[0][1] = 2.
-   For i = 0 and j = 2, ans[2][0] = matrix[0][2] = 3.

3. Second Row Transposition:

-   For i = 1 and j = 0, ans[0][1] = matrix[1][0] = 4.
-   For i = 1 and j = 1, ans[1][1] = matrix[1][1] = 5.
-   For i = 1 and j = 2, ans[2][1] = matrix[1][2] = 6.

4. Final Transposed Matrix: ans = [
   [1, 4],
   [2, 5],
   [3, 6]
   ]
