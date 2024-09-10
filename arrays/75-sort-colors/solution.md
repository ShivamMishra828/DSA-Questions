# Sort Colors (Question 75)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/sort-colors/)

Given an array with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

### Constraints

-   n is the number of objects in the array
-   The colors are represented by integers: 0 (red), 1 (white), and 2 (blue)

## Solution

```cpp
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int i = 0;
        int j = arr.size()-1;
        int index = 0;

        while(index <= j) {
            if(arr[index] == 0) {
                swap(arr[index], arr[i]);
                index++;
                i++;
            }
            else if(arr[index] == 2) {
                swap(arr[index], arr[j]);
                j--;
            }
            else {
                index++;
            }
        }
    }
};
```

## Explanation

-   We use three pointers: i, j, and index
-   i points to the next position where a 0 should be placed
-   j points to the next position where a 2 should be placed
-   index is the current element being processed
-   We iterate through the array, swapping elements as needed to maintain the correct order

### Important Concepts

-   Dutch National Flag algorithm
-   Three-pointer technique
-   In-place sorting

## Notes

-   We don't increment index when arr[index] == 2 because we need to re-check the swapped element
-   We use swap to exchange elements in the array

### Time Complexity

O(n), where n is the number of elements in the array

### Space Complexity

O(1), as we only use a constant amount of space to store the pointers

### Edge Cases

-   Empty array
-   Array with only one element
-   Array with only two elements
-   Array with all elements of the same color
