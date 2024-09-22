# Insertion Sort

## Problem Statement

Sort an array of integers in ascending order.

## Solution

```cpp
class Solution {
public:
    // Function to sort the array using Insertion Sort
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // Iterate through the array starting from the second element
        for(int i = 1; i < n; i++) {
            int temp = nums[i]; // Store current element
            int j = i - 1; // Initialize index for comparison

            // Shift elements greater than temp to the right
            for(; j >= 0; j--) {
                if(nums[j] > temp) {
                    nums[j + 1] = nums[j]; // Shift element
                } else {
                    break; // Found correct position for temp
                }
            }

            // Insert temp at its correct position
            nums[j + 1] = temp;
        }

        return nums;
    }
};
```

## Explanation

Insertion Sort is a simple sorting algorithm that works by iterating through the array one element at a time, inserting each element into its proper position within the previously sorted portion.
Steps:

1. Iterate through the array starting from the second element.
2. Store the current element (temp) and initialize index j to the previous element.
3. Shift elements greater than temp to the right until the correct position is found.
4. Insert temp at its correct position.

### Time Complexity

-   Best-case: O(n)
-   Average-case: O(n^2)
-   Worst-case: O(n^2)

### Space Complexity

O(1): In-place sorting, no extra space required.

### Dry Run Example

Input:
nums = [5, 2, 8, 1, 9]
Steps:

1. i = 1, temp = 2
    - Compare 5 and 2, shift 5: [5, _, 8, 1, 9]
    - Insert 2 at position 0: [2, 5, 8, 1, 9]
2. i = 2, temp = 8
    - No shift needed, insert 8 at position 2: [2, 5, 8, 1, 9]
3. i = 3, temp = 1
    - Compare 2 and 1, shift 2: [1, _, 5, 8, 9]
    - Insert 1 at position 0: [1, 2, 5, 8, 9]
4. i = 4, temp = 9 - No shift needed, insert 9 at position 4: [1, 2, 5, 8, 9]
   Output: [1, 2, 5, 8, 9]

### Edge Cases

-   Empty array
-   Single-element array
-   Duplicate elements
-   Already sorted array
