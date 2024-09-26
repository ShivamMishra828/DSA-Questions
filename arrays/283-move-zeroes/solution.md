# Move Zeroes (Question 283)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/move-zeroes/)

Given an integer array `nums`, move all `0`s to the end of the array while maintaining the relative order of the non-zero elements. You must do this in-place without making a copy of the array.

### Constraints

-   1 ≤ `nums.length` ≤ 10^4
-   `nums[i]` can be 0 or any integer

## Solution

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;  // This pointer keeps track of the next non-zero element's position.

        // Iterate through the array
        for(int i = 0; i < nums.size(); i++) {
            // If the current element is not zero, swap it with the element at index j
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;  // Increment j to track the next position for non-zero elements
            }
        }
    }
};
```

## Explanation

1. We maintain two pointers:

    - i: To iterate through the entire array.
    - j: To track the next position where a non-zero element should be placed.

2. As we iterate through the array:

    - If we encounter a non-zero element at i, we swap it with the element at index j and then increment j to point to the next available position.

3. After processing the entire array, all non-zero elements are placed at the beginning of the array in their original order, and all zeros are shifted to the end.

### Important Concepts

-   In-place operation: We perform swaps directly within the array to avoid using extra space.
-   Two-pointer technique: This allows us to maintain the relative order of non-zero elements while pushing zeros to the end.

### Dry Run

Input: [0, 1, 0, 3, 12]

1.  Initial State: nums = [0, 1, 0, 3, 12], j = 0.

2.  Step 1:

    - i = 0, nums[0] = 0 (skip as it's zero).

3.  Step 2:

    - i = 1, nums[1] = 1 (non-zero).
    - Swap nums[1] with nums[0]: nums = [1, 0, 0, 3, 12].
    - Increment j to 1.

4.  Step 3:

    - i = 2, nums[2] = 0 (skip as it's zero).

5.  Step 4:

    - i = 3, nums[3] = 3 (non-zero).
    - Swap nums[3] with nums[1]: nums = [1, 3, 0, 0, 12].
    - Increment j to 2.

6.  Step 5:

        - i = 4, nums[4] = 12 (non-zero).
        - Swap nums[4] with nums[2]: nums = [1, 3, 12, 0, 0].
        - Increment j to 3.

    Final Output: [1, 3, 12, 0, 0]

### Time Complexity

O(n): We traverse the array once, where n is the size of the array.

### Space Complexity

O(1): The operation is done in-place, so no extra space is used.

### Edge Cases

-   The array contains no zeros.
-   All elements are zero.
-   The array contains a mix of zeros and non-zero elements in different positions.
