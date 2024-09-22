# Bubble Sort

## Problem Statement

Sort an array of integers in ascending order.

## Solution

```cpp
class Solution {
public:
    // Function to sort the array using Bubble Sort
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // Iterate through the array
        for(int i = 1; i < n; i++) {
            // Compare adjacent elements and swap if needed
            for(int j = 0; j < n - i; j++) {
                if(nums[j] > nums[j + 1]) {
                    // Swap adjacent elements
                    swap(nums[j + 1], nums[j]);
                }
            }
        }

        return nums;
    }
};
```

## Explanation

Bubble Sort is a simple sorting algorithm that works by repeatedly iterating through the array, comparing adjacent elements, and swapping them if they are in the wrong order.
Steps: 1. Iterate through the array n-1 times. 2. In each iteration, compare adjacent elements. 3. If adjacent elements are in the wrong order, swap them. 4. Repeat steps 2-3 until the end of the array.

### Time Complexity

    Best-case: O(n)
    Average-case: O(n^2)
    Worst-case: O(n^2)

### Space Complexity

    O(1): In-place sorting, no extra space required.

### Dry Run Example

Input:
nums = [5, 2, 8, 1, 9]
Steps:

1. i = 1, j = 0-3
    - Compare 5 and 2, swap: [2, 5, 8, 1, 9]
    - Compare 5 and 8, no swap -
    - Compare 8 and 1, swap: [2, 5, 1, 8, 9] -
    - Compare 8 and 9, no swap
2. i = 2, j = 0-2
    - Compare 2 and 5, no swap -
    - Compare 5 and 1, swap: [2, 1, 5, 8, 9] -
    - Compare 5 and 8, no swap
3. i = 3, j = 0-1
    - Compare 2 and 1, swap: [1, 2, 5, 8, 9] -
    - Compare 2 and 5, no swap

Output: [1, 2, 5, 8, 9]

### Edge Cases

-   Empty array
-   Single-element array
-   Duplicate elements
    -Already sorted array

O(1): In-place sorting, no extra space required.
