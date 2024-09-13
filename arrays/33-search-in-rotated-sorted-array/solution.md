# Search in Rotated Sorted Array (Question 33)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/search-in-rotated-sorted-array/)

Given the array `nums` which is sorted in ascending order (but rotated at an unknown pivot), write a function to search for a given `target` value. If the target exists, return its index. Otherwise, return `-1`.

You must write an algorithm with O(log n) runtime complexity.

### Constraints

-   1 ≤ nums.length ≤ 5000
-   -10^4 ≤ nums[i] ≤ 10^4
-   All values of `nums` are unique.
-   `nums` is guaranteed to be rotated at some pivot.
-   `target` can be any integer within the array's value range.

## Solution

```cpp
class Solution {
public:
    // Function to find the pivot index (where the array is rotated)
    int findPivot(vector<int>& nums) {
        int s = 0; // Start index
        int e = nums.size() - 1; // End index
        int n = nums.size();
        int mid = s + (e - s) / 2; // Calculate mid-point

        // Perform binary search to find the pivot
        while (s <= e) {
            // If start and end converge, the pivot is found
            if (s == e) {
                return s;
            }

            // Check if mid is the pivot point (mid > mid + 1)
            if (mid + 1 < n && nums[mid] > nums[mid + 1]) {
                return mid; // Mid is the pivot as it's greater than the next element
            }

            // Check if mid-1 is the pivot point (mid < mid - 1)
            else if (mid - 1 >= 0 && nums[mid] < nums[mid - 1]) {
                return mid - 1; // Mid-1 is the pivot as mid is smaller than the previous element
            }

            // If the left side (nums[start] to nums[mid]) is sorted, move right
            else if (nums[s] <= nums[mid]) {
                s = mid + 1; // Move to the right half to search for the pivot
            }

            // Otherwise, move left
            else {
                e = mid - 1; // Move to the left half to search for the pivot
            }

            // Recalculate mid for the next iteration
            mid = s + (e - s) / 2;
        }

        return -1; // Return -1 if no pivot is found (though this case won't occur as there's always a pivot)
    }

    // Standard binary search function
    int binarySearch(vector<int>& nums, int s, int e, int target) {
        int mid = s + (e - s) / 2; // Calculate mid-point

        // Perform binary search to find the target
        while (s <= e) {
            if (nums[mid] == target) {
                return mid; // Target found
            }
            else if (nums[mid] > target) {
                e = mid - 1; // If target is smaller, move left
            }
            else {
                s = mid + 1; // If target is larger, move right
            }

            // Recalculate mid for the next iteration
            mid = s + (e - s) / 2;
        }

        return -1; // Target not found
    }

    // Function to search for the target in the rotated array
    int search(vector<int>& nums, int target) {
        int pivotIndex = findPivot(nums);  // Find the pivot index
        int ans = -1;  // Initialize the result to -1 (not found)

        // If the target lies between nums[0] and nums[pivotIndex], search in the left part
        if (target >= nums[0] && target <= nums[pivotIndex]) {
            ans = binarySearch(nums, 0, pivotIndex, target);
        }
        // Otherwise, search in the right part
        else {
            ans = binarySearch(nums, pivotIndex + 1, nums.size() - 1, target);
        }

        return ans; // Return the final result (index of target or -1 if not found)
    }
};
```

## Explanation

-   The array is rotated at an unknown pivot, and we need to search for the target value efficiently.
-   The first step is to find the pivot point, where the array is rotated. This is done using a modified binary search in the findPivot function.
-   Once we have the pivot, the array can be viewed as two sorted subarrays:
-   One subarray from 0 to pivot.
-   The other subarray from pivot + 1 to the end of the array.
-   We perform a binary search in the appropriate subarray depending on where the target value falls relative to the pivot.

### Important Concepts

-   Binary Search: This problem is solved in O(log n) using binary search techniques.
-   Pivot Finding: The key to solving the rotated array search problem is finding the pivot where the array is split into two sorted subarrays.
-   mid + 1: We check if nums[mid] > nums[mid + 1] to find the exact point of rotation.
-   mid - 1: We check nums[mid] < nums[mid - 1] to catch the other side of the pivot.

### Notes

-   The array is rotated and split into two parts, but we can handle this using the binary search technique.
-   The approach ensures efficient search with O(log n) time complexity.

### Time Complexity

-   O(log n), where n is the length of the array, as we use binary search both to find the pivot and to search in one of the subarrays.

### Space Complexity

O(1), as no extra space is used other than a few variables.

### Edge Cases

-   The array is not rotated (i.e., pivot is at the start or end).
-   The target is the smallest or largest element in the array.
-   The target does not exist in the array.
