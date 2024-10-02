# Spiral Matrix (Question 54)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/spiral-matrix/)

Given an `m x n` matrix, return all elements of the matrix in spiral order.

### Constraints

-   m == matrix.length
-   n == matrix[i].length
-   1 ≤ m, n ≤ 10
-   -100 ≤ matrix[i][j] ≤ 100

## Solution

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        ArrayList<Integer> result = new ArrayList<>();  // List to store the spiral order
        if (matrix.length == 0) return result;  // Edge case: empty matrix

        int rows = matrix.length;  // Total number of rows
        int cols = matrix[0].length;  // Total number of columns
        int startRow = 0;  // Starting row
        int endRow = rows - 1;  // Ending row
        int startCol = 0;  // Starting column
        int endCol = cols - 1;  // Ending column

        while (startRow <= endRow && startCol <= endCol) {
            // Traverse from left to right across the topmost row
            for (int i = startCol; i <= endCol; i++) {
                result.add(matrix[startRow][i]);
            }

            // Traverse downwards along the rightmost column
            for (int i = startRow + 1; i <= endRow; i++) {
                result.add(matrix[i][endCol]);
            }

            // Traverse from right to left along the bottom row (if necessary)
            if (startRow != endRow) {  // Check to avoid duplicate row
                for (int i = endCol - 1; i >= startCol; i--) {
                    result.add(matrix[endRow][i]);
                }
            }

            // Traverse upwards along the leftmost column (if necessary)
            if (startCol != endCol) {  // Check to avoid duplicate column
                for (int i = endRow - 1; i >= startRow + 1; i--) {
                    result.add(matrix[i][startCol]);
                }
            }

            // Move towards the inner spiral
            startCol++;
            endCol--;
            startRow++;
            endRow--;
        }
        return result;
    }
}
```

## Explanation

-   Initialization: We initialize pointers for rows (startRow, endRow) and columns (startCol, endCol) to track the current boundary of the spiral traversal.
-   Spiral Traversal: We proceed in four steps:
    1. Traverse from the leftmost column to the rightmost column (left to right).
    2. Traverse from the top row to the bottom row along the rightmost column (top to bottom).
    3. Traverse from the rightmost column to the leftmost column (right to left) if there are still rows remaining.
    4. Traverse from the bottom row back to the top row along the leftmost column (bottom to top) if there are still columns remaining.
-   Update Boundaries: After each full spiral, we move inward by updating the start and end pointers for rows and columns.

### Important Concepts

-   Boundary Control: The startRow, endRow, startCol, and endCol pointers ensure that we don't revisit any element.
-   Conditional Checks: We check for special cases where there's only one row or one column left, to avoid duplication.

### Time Complexity

O(m \* n): We traverse each element of the matrix exactly once.

### Space Complexity

O(m \* n): The output list stores all the elements of the matrix.

### Edge Cases

-   Empty matrix.
-   Single row or single column matrix.
-   Matrices with varying dimensions (e.g., 2x3, 4x4, etc.).

### Dry Run

Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

1.  Initial State:

    -   startRow = 0, endRow = 2, startCol = 0, endCol = 2

2.  First Spiral:

    -   Traverse top row ([1, 2, 3])
    -   Traverse right column ([6, 9])
    -   Traverse bottom row ([8, 7])
    -   Traverse left column ([4])

3.  Second Spiral:

    -   Traverse center ([5])

Final Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]
