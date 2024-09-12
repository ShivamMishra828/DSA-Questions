# Remove Duplicates from Sorted Array (Question 26)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

Given a sorted array `nums`, remove the duplicates in-place such that each element appears only once and return the new length.

Do not allocate extra space for another array; you must do this by modifying the input array in-place with O(1) extra memory.

### Constraints

-   1 ≤ nums.length ≤ 3 \* 10^4
-   -100 ≤ nums[i] ≤ 100
-   `nums` is sorted in non-decreasing order.

## Solution

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();   // Get the size of the array
        int j = 0;  // Initialize j to track the position of unique elements

        // Start loop from the second element
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[j]) {  // If current element is not a duplicate
                nums[j + 1] = nums[i];  // Move the unique element to the next position
                j++;  // Increment the index of the unique position
            }
        }

        return j + 1;  // Return the number of unique elements
    }
};
```

## Explanation

-   The solution uses two pointers, i and j.
-   Pointer j keeps track of the position where the next unique element should be placed, while i iterates over the array.
-   If nums[i] is different from nums[j], we increment j and place nums[i] at nums[j + 1].
-   Finally, we return j + 1 as the length of the modified array that contains unique elements.

### Important Concepts

-   Two-pointer technique to modify the array in-place.
-   Handling sorted arrays to remove duplicates efficiently.

## Notes

-   This approach modifies the array in-place without using extra space.
-   The algorithm ensures that all unique elements are placed at the beginning of the array, and their relative order is preserved.

### Time Complexity

O(n), where n is the length of the array. We traverse the array once.

### Space Complexity

O(1), as we use a constant amount of extra space.

### Edge Cases

-   An array with all unique elements.
-   An array with all elements the same.
-   An array with only one element.
