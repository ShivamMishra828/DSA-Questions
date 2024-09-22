# Selection Sort

## Problem Statement

Sort an array of integers in ascending order.

## Solution

```cpp
class Solution {
public:
    // Function to sort the array using Selection Sort
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // Iterate through the array
        for(int i = 0; i < n - 1; i++) {
            // Initialize the minimum index
            int minIndex = i;

            // Find the minimum element in the unsorted part of the array
            for(int j = i + 1; j < n; j++) {
                if(nums[minIndex] > nums[j]) {
                    minIndex = j;
                }
            }

            // Swap the minimum element with the first element of the unsorted part
            swap(nums[minIndex], nums[i]);
        }

        return nums;
    }
};
```

## Explanation

Selection Sort is a simple sorting algorithm that works by repeatedly finding the minimum element from the unsorted part of the array and swapping it with the first unsorted element.

### Steps:

1. Initialize the minimum index to the current index.
2. Iterate through the unsorted part of the array to find the minimum element.
3. Swap the minimum element with the first element of the unsorted part.
4. Repeat steps 1-3 until the entire array is sorted.

### Time Complexity

-   Best-case: O(n^2)
-   Average-case: O(n^2)
-   Worst-case: O(n^2)

### Space Complexity

O(1): In-place sorting, no extra space required.

### Dry Run Example

Input:
nums = [5, 2, 8, 1, 9]
Steps:

1. i = 0, minIndex = 0
    - Find minimum: minIndex = 3 (nums[3] = 1)
    - Swap: nums[0] = 1, nums[3] = 5
    - Array: [1, 2, 8, 5, 9]
2. i = 1, minIndex = 1
    - Find minimum: minIndex = 1 (nums[1] = 2)
    - No swap needed
    - Array: [1, 2, 8, 5, 9]
3. i = 2, minIndex = 2
    - Find minimum: minIndex = 3 (nums[3] = 5)
    - Swap: nums[2] = 5, nums[3] = 8
    - Array: [1, 2, 5, 8, 9]
4. i = 3, minIndex = 3
    - Find minimum: minIndex = 3 (nums[3] = 8)
    - No swap needed
    - Array: [1, 2, 5, 8, 9]

Output:
[1, 2, 5, 8, 9]

### Edge Cases

-   Empty array
-   Single-element array
-   Duplicate elements
-   Already sorted array
