# Peak Index in a Mountain Array (Question 852)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/peak-index-in-a-mountain-array/)

An array `arr` is a mountain if:

-   `arr.length >= 3`
-   There exists some `i` with `0 < i < arr.length - 1` such that:
    -   `arr[0] < arr[1] < ... < arr[i - 1] < arr[i]`
    -   `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

Given a mountain array `arr`, return the index `i` such that `arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`.

You must solve it in `O(log n)` time complexity.

### Constraints

-   3 ≤ arr.length ≤ 10^4
-   0 ≤ arr[i] ≤ 10^6
-   The array `arr` is guaranteed to be a mountain array.

## Solution

```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;  // Initialize the start pointer
        int end = arr.size() - 1;  // Initialize the end pointer
        int mid = start + (end - start) / 2;  // Calculate the middle index

        // Binary search to find the peak element
        while (start <= end) {
            if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
                return mid;  // If mid is greater than its neighbors, it's the peak
            }
            else if (arr[mid] > arr[mid + 1]) {
                end = mid - 1;  // If mid is part of the descending slope, move left
            }
            else {
                start = mid + 1;  // If mid is part of the ascending slope, move right
            }
            mid = start + (end - start) / 2;  // Update mid for the next iteration
        }

        return -1;  // This will never be reached since there is always a peak
    }
};
```

### Explanation

-   The problem is solved using binary search to efficiently find the peak index.
-   The start and end pointers are used to traverse the array in search of the peak element.
-   We calculate the mid index, and if arr[mid] is greater than its neighbors (arr[mid-1] and arr[mid+1]), then mid is the peak index, and we return it.
-   If arr[mid] is part of the descending slope (i.e., arr[mid] > arr[mid + 1]), we move the end pointer to mid - 1.
-   If arr[mid] is part of the ascending slope (i.e., arr[mid] < arr[mid + 1]), we move the start pointer to mid + 1.

### Important Concepts

Binary Search: This allows us to search for the peak element in logarithmic time (O(log n)).
The peak element in a mountain array is the only element that is greater than its neighbors.

## Notes

-   This approach guarantees an efficient search with O(log n) time complexity.
-   The use of binary search is optimal for this problem because of the guaranteed mountain structure of the array.

### Time Complexity

O(log n), where n is the length of the array. Binary search is used to find the peak element.

### Space Complexity

O(1), as no extra space is used other than the variables.

### Edge Cases

-   The array is small (minimum length of 3).
-   The peak element is at the start or end of the array.
