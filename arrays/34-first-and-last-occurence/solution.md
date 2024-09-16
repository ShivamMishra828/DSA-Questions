# Find First and Last Position of Element in Sorted Array (Question 34)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

Given an array of integers `nums` sorted in ascending order, find the starting and ending position of a given target value. If the target is not found in the array, return `[-1, -1]`.

### Constraints

-   Time complexity must be O(log n).
-   The array is sorted in non-decreasing order.

## Solution

```cpp
class Solution {
public:
    // Function to find the first occurrence of the target
    int firstOccurence(vector<int>& nums, int target) {
        int s = 0;  // Start of the search range
        int e = nums.size() - 1;  // End of the search range
        int mid = s + (e - s) / 2;  // Mid-point of the range
        int ans = -1;  // Variable to store the result

        // Binary search to find the first occurrence
        while (s <= e) {
            if (nums[mid] == target) {
                ans = mid;  // Store the index if we find the target
                e = mid - 1;  // Move the end to mid - 1 to find earlier occurrence
            }
            else if (nums[mid] > target) {
                e = mid - 1;  // Search in the left half
            } else {
                s = mid + 1;  // Search in the right half
            }
            mid = s + (e - s) / 2;  // Update mid for the next iteration
        }
        return ans;
    }

    // Function to find the last occurrence of the target
    int lastOccurence(vector<int>& nums, int target) {
        int s = 0;  // Start of the search range
        int e = nums.size() - 1;  // End of the search range
        int mid = s + (e - s) / 2;  // Mid-point of the range
        int ans = -1;  // Variable to store the result

        // Binary search to find the last occurrence
        while (s <= e) {
            if (nums[mid] == target) {
                ans = mid;  // Store the index if we find the target
                s = mid + 1;  // Move the start to mid + 1 to find later occurrence
            }
            else if (nums[mid] > target) {
                e = mid - 1;  // Search in the left half
            } else {
                s = mid + 1;  // Search in the right half
            }
            mid = s + (e - s) / 2;  // Update mid for the next iteration
        }
        return ans;
    }

    // Function to return the first and last position of the target
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first = firstOccurence(nums, target);  // Get the first occurrence
        int second = lastOccurence(nums, target);  // Get the last occurrence
        ans.push_back(first);  // Add the first occurrence to the result
        ans.push_back(second);  // Add the last occurrence to the result
        return ans;
    }
};
```

## Explanation

-   firstOccurence: This function performs a binary search to find the first occurrence of the target in the sorted array. It continues searching even after finding the target to ensure it finds the first position.

-   lastOccurence: This function similarly performs a binary search but ensures it finds the last occurrence of the target by adjusting the search boundaries.

-   searchRange: This function calls both firstOccurence and lastOccurence and returns their results as a vector. If the target is not found, both functions return -1.

### Important Concepts

-   Binary Search: The problem requires O(log n) time complexity, so a binary search is employed to efficiently find the first and last positions of the target.
-   Edge Cases: The algorithm handles edge cases where the target is not present in the array, or there is only one occurrence of the target.

## Notes

-   Binary search ensures that the solution is optimal with logarithmic time complexity.
-   If the target is not found, the function will return [-1, -1].

### Time Complexity

O(log n) for both firstOccurence and lastOccurence, as they use binary search.

### Space Complexity

O(1) since the space used is constant apart from the input array.

### Edge Cases

-   The target is not present in the array.
-   All elements in the array are the target.
-   The target appears only once in the array.
-   The array has only one element.
