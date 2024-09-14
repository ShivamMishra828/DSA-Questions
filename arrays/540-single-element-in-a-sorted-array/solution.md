# Single Element in a Sorted Array (Question 540)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/single-element-in-a-sorted-array/)

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

### Constraints

-   The input array is sorted.
-   Every element appears twice, except for one element which appears exactly once.

## Solution

### Original Code

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0; // Start of the search range
        int e = nums.size() - 1; // End of the search range
        int mid = s + (e - s) / 2; // Mid-point of the current range

        // Binary search to find the single element
        while (s <= e) {
            // If start equals end, we have found the single element
            if (s == e) {
                return nums[s];
            }

            // Edge case: if mid is the first element and not equal to the next one
            if (mid == 0) {
                if (nums[mid] != nums[mid + 1]) {
                    return nums[mid];
                }
            }

            // Edge case: if mid is the last element and not equal to the previous one
            if (mid == nums.size() - 1) {
                if (nums[mid] != nums[mid - 1]) {
                    return nums[mid];
                }
            }

            // If mid element is not equal to its neighbors, it's the single element
            if ((mid >= 0 && nums[mid] != nums[mid - 1]) && mid <= nums.size() - 1 && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // Check the parity of the index and decide where to move next
            // If mid is even and matches the previous element, move to the left
            else if (mid % 2 == 0) {
                if (nums[mid] == nums[mid - 1]) {
                    e = mid - 1; // Move left
                } else {
                    s = mid + 1; // Move right
                }
            }
            // If mid is odd and matches the next element, move left, otherwise move right
            else {
                if (nums[mid] == nums[mid + 1]) {
                    e = mid - 1; // Move left
                } else {
                    s = mid + 1; // Move right
                }
            }
            // Recalculate mid for the next iteration
            mid = s + (e - s) / 2;
        }

        // Return -1 if no element is found (this should not happen per problem constraints)
        return -1;
    }
};
```

### Optimized Code

```cpp
class Solution {
public:
int singleNonDuplicate(vector<int>& nums) {
int s = 0; // Start of the search range
int e = nums.size() - 1; // End of the search range

        // Binary search loop to find the single element
        while (s < e) {
            int mid = s + (e - s) / 2;

            // Adjust mid to always point to the first element in a pair
            if (mid % 2 == 1) {
                mid--;
            }

            // If mid and the next element form a pair, move search to the right
            if (nums[mid] == nums[mid + 1]) {
                s = mid + 2;
            } else {
                // Otherwise, move search to the left
                e = mid;
            }
        }

        // At the end, s will point to the single element
        return nums[s];
    }

};
```

## Explanation

### Original Approach:

-   The original code uses binary search to find the single element.
-   We calculate the mid-point and check if the element is different from its neighbors.
-   Depending on the element’s parity and position in the array, we adjust the search range.
-   Time Complexity: O(log n)
-   Space Complexity: O(1)

### Optimized Approach:

-   The optimized code simplifies the binary search by using pairs of elements.
-   The idea is that elements are paired except for the single one, so the index of the single element will affect the pairing.
-   We move the search range based on whether the mid index and its neighbor form a pair.
-   If mid is even and matches mid+1, the single element must be on the right; otherwise, it’s on the left.
-   The search continues until the start and end pointers converge to the single element.
-   Time Complexity: O(log n)
-   Space Complexity: O(1)

### Important Concepts

-   Binary Search: Both solutions utilize binary search to reduce the search space in logarithmic time.
-   Pair Matching: The optimized solution focuses on identifying pairs in the array and determining where the mismatch (single element) lies.

## Notes

-   Both solutions are efficient and use logarithmic time complexity.
-   The optimized version simplifies the checks for whether the mid index forms part of a pair, making it a more elegant solution.

### Time Complexity

O(log n), since both approaches use binary search.

### Space Complexity

O(1), since no additional space is required beyond a few variables.

### Edge Cases

-   The single element is at the start or end of the array.
-   The array has only one element.
