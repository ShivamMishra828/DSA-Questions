# Set Matrix Zeroes (Question 73)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/set-matrix-zeroes/)

Given an `m x n` integer matrix, if an element is 0, set its entire row and column to 0s. You must do it **in-place**.

### Constraints

-   `m == matrix.length`
-   `n == matrix[0].length`
-   `1 <= m, n <= 200`
-   `-2^31 <= matrix[i][j] <= 2^31 - 1`

### Solution

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;   // Number of rows
        int n = matrix[0].length; // Number of columns
        boolean isRow = false;    // Flag to check if first row needs to be set to zero
        boolean isCol = false;    // Flag to check if first column needs to be set to zero

        // Step 1: Determine which rows and columns need to be set to zero
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;   // Set marker for the column
                    matrix[i][0] = 0;   // Set marker for the row
                    if(i == 0) isRow = true;   // Check if the first row needs to be zeroed
                    if(j == 0) isCol = true;   // Check if the first column needs to be zeroed
                }
            }
        }

        // Step 2: Set matrix elements to zero based on markers
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle first row
        if(isRow) {
            for(int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }

        // Step 4: Handle first column
        if(isCol) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
}
```

## Explanation

-   Step 1: We iterate through the matrix. For every zero we find, we mark the corresponding row and column using the first row and first column as markers. If any zero is found in the first row or first column, we set isRow or isCol to true.
-   Step 2: We iterate over the matrix starting from the second row and second column. If the first element of the row or column is marked as 0, we set the corresponding cell to 0.
-   Step 3: If the isRow flag is true, we set the entire first row to 0.
-   Step 4: If the isCol flag is true, we set the entire first column to 0.

### Important Concepts

1. In-Place Transformation: This solution uses the first row and column as a way to store information about which rows and columns need to be set to 0. This avoids using extra space, making the solution space-efficient.

2. Flags: We use flags isRow and isCol to handle the special case when there are 0s in the first row or column.

### Time Complexity

O(m \* n): We traverse the entire matrix twice, first to identify the zeroes and then to update the matrix.

### Space Complexity

O(1): The space complexity is constant because we are only using a few extra variables (flags) and modifying the matrix in-place.

### Dry Run

Input:- matrix = [
[1, 1, 1],
[1, 0, 1],
[1, 1, 1]
]

Execution Steps

1. Initial Marking:

    - In the second row, there's a 0 at position (1,1). Set the markers:
      matrix[0][1] = 0;
      matrix[1][0] = 0;
    - After this, the matrix looks like:
      [
      [1, 0, 1],
      [0, 0, 1],
      [1, 1, 1]
      ]

2. Update Based on Markers:

-   For i = 1, j = 1, since matrix[1][0] == 0 or matrix[0][1] == 0, set matrix[1][1] = 0.
-   For i = 1, j = 2, no change as matrix[0][2] != 0 and matrix[1][0] != 0.
-   For i = 2, j = 1, set matrix[2][1] = 0.
-   Matrix after this step: [
    [1, 0, 1],
    [0, 0, 0],
    [1, 0, 1]
    ]

3. Handle First Row and Column:

-   Since isCol = false, no change in the first column.
-   Since matrix[0][1] == 0, set the entire first row to zero
-   matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[0][2] = 1;

-   Final Output: [
    [1, 0, 1],
    [0, 0, 0],
    [1, 0, 1]
    ]
