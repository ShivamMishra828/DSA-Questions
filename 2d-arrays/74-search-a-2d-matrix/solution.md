# Search a 2D Matrix (Question 74)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/search-a-2d-matrix/)

Write an efficient algorithm that searches for a value in an `m x n` matrix. Integers in each row are sorted from left to right, and the first integer of each row is greater than the last integer of the previous row.

### Constraints

-   `m == matrix.length`
-   `n == matrix[i].length`
-   `1 <= m, n <= 100`
-   `-10^4 <= matrix[i][j], target <= 10^4`

## Solution

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // Get dimensions of the matrix
        int m = matrix.length;
        int n = matrix[0].length;

        // Initialize binary search boundaries
        int left = 0, right = m * n - 1;

        // Perform binary search
        while (left <= right) {
            // Calculate the middle index in the "virtual" 1D matrix
            int mid = left + (right - left) / 2;

            // Access the middle element by converting the 1D index into 2D coordinates
            int mid_val = matrix[mid / n][mid % n];

            // If target is found, return true
            if (mid_val == target)
                return true;

            // If mid_val is less than target, search the right half
            else if (mid_val < target)
                left = mid + 1;

            // If mid_val is greater than target, search the left half
            else
                right = mid - 1;
        }

        // Return false if target is not found
        return false;
    }
}
```

## Explanation

-   The matrix is treated as a 1D array by calculating an index using mid / n and mid % n to map back to the 2D matrix.
-   Binary search is performed on this "virtual" 1D array, making the solution efficient with a time complexity of O(log(m \* n)).
-   The algorithm works because the matrix is sorted row-wise and column-wise.

### Important Concepts

-   Binary Search: Binary search reduces the time complexity by half each time, making it highly efficient.
-   Matrix Indexing: Treating the matrix as a 1D array allows using the binary search technique directly.

### Time Complexity

O(log(m _ n)): We are performing binary search over m _ n elements.

### Space Complexity

O(1): No additional space is required except for the variables.

### Edge Cases

-   The matrix is empty.
-   The target is smaller than the smallest element or larger than the largest element in the matrix.

### Dry Run

Input:- matrix = [
[1, 3, 5, 7],
[10, 11, 16, 20],
[23, 30, 34, 60]
]
target = 3

Execution Steps

1. Initial Setup:

-   m = 3, n = 4
-   left = 0, right = 11 (m \* n - 1)

2. First Iteration:

-   mid = 5 (left + (right - left) / 2)
-   mid_val = matrix[5 / 4][5 % 4] = matrix[1][1] = 11
-   Since 11 > 3, we update right = mid - 1 = 4.

3. Second Iteration:

-   mid = 2 (left + (right - left) / 2)
-   mid_val = matrix[2 / 4][2 % 4] = matrix[0][2] = 5
-   Since 5 > 3, we update right = mid - 1 = 1.

4. Third Iteration:

-   mid = 0 (left + (right - left) / 2)
-   mid_val = matrix[0 / 4][0 % 4] = matrix[0][0] = 1
-   Since 1 < 3, we update left = mid + 1 = 1.

5. Fourth Iteration:

-   mid = 1 (left + (right - left) / 2)
-   mid_val = matrix[1 / 4][1 % 4] = matrix[0][1] = 3
-   Since mid_val == 3, return true.

Final Output:- true
