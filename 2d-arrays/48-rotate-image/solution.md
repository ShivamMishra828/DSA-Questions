# Rotate Image (Question 48)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/rotate-image/)

You are given an `n x n` 2D matrix representing an image, rotate the image by **90 degrees (clockwise)**.

You have to rotate the image **in-place**, which means you have to modify the input 2D matrix directly. **Do not allocate another 2D matrix and do the rotation.**

### Constraints

-   `n == matrix.length == matrix[i].length`
-   `1 <= n <= 20`
-   `-1000 <= matrix[i][j] <= 1000`

### Solution

```java
class Solution {
    public void rotate(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        // Step 1: Reverse the rows (first row swaps with last row, and so on)
        int startRow = 0;
        int endRow = m - 1;

        while (startRow < endRow) {
            for (int i = 0; i < n; i++) {
                int temp = matrix[startRow][i];
                matrix[startRow][i] = matrix[endRow][i];
                matrix[endRow][i] = temp;
            }
            startRow++;
            endRow--;
        }

        // Step 2: Transpose the matrix (convert rows into columns)
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
}
```

## Explanation

1. Step 1: Reverse the rows

-   First, reverse the order of the rows in the matrix. Swap the first row with the last row, the second row with the second-to-last row, and so on. After this step, the matrix will be vertically flipped.

2. Step 2: Transpose the matrix

-   After flipping, transpose the matrix, which means swapping matrix[i][j] with matrix[j][i]. This turns rows into columns.

The combination of these two steps results in a 90-degree clockwise rotation.

### Time Complexity

O(n^2): We are processing each element in the matrix twice, once in the row reversal and once during the transposition.

### Space Complexity

O(1): The rotation is done in place, without using any extra space.

### Dry Run

Input: matrix = [
[1, 2, 3],
[4, 5, 6],
[7, 8, 9]
]

Execution Steps

1. Step 1: Reverse Rows

-   Swap the first row with the last row: [
    [7, 8, 9],
    [4, 5, 6],
    [1, 2, 3]
    ]

2. Step 2: Transpose the Matrix

-   Swap matrix[i][j] with matrix[j][i]:

    -   Swap matrix[0][1] with matrix[1][0]: (8 and 4)
    -   Swap matrix[0][2] with matrix[2][0]: (9 and 1)
    -   Swap matrix[1][2] with matrix[2][1]: (6 and 2)

Output:- [
[7, 4, 1],
[8, 5, 2],
[9, 6, 3]
]
