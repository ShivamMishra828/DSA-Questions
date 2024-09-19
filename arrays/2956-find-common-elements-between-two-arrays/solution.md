# Find Common Elements Between Two Arrays (Question 2956)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/find-common-elements-between-two-arrays/)

Given two integer arrays `nums1` and `nums2`, find how many elements of `nums1` are present in `nums2`, and vice versa. Return the counts in a vector.

### Constraints

-   The size of both arrays can be large, so an efficient approach is preferred.
-   The arrays can contain duplicate values.

## Solution

```cpp
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int firstArrCount = 0;  // Count of elements in nums1 found in nums2
        int secondArrCount = 0;  // Count of elements in nums2 found in nums1
        vector<int> ans;  // Vector to store the final result

        // Loop through nums1 and check if each element is present in nums2
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {  // If common element is found
                    firstArrCount++;  // Increment count for nums1
                    break;  // No need to check further for this element
                }
            }
        }

        // Loop through nums2 and check if each element is present in nums1
        for(int i = 0; i < nums2.size(); i++) {
            for(int j = 0; j < nums1.size(); j++) {
                if(nums2[i] == nums1[j]) {  // If common element is found
                    secondArrCount++;  // Increment count for nums2
                    break;  // No need to check further for this element
                }
            }
        }

        // Store the counts in the result vector
        ans.push_back(firstArrCount);  // First value: common elements from nums1
        ans.push_back(secondArrCount);  // Second value: common elements from nums2

        return ans;  // Return the result vector
    }
};
```

## Explanation

-   firstArrCount: This variable counts how many elements from nums1 are present in nums2.
-   secondArrCount: This variable counts how many elements from nums2 are present in nums1.
    Approach
-   For each element in nums1, we compare it with each element in nums2. If a match is found, we increment firstArrCount and move to the next element of nums1.

-   We repeat a similar process for nums2, comparing it with nums1 and incrementing secondArrCount for each match.

-   After both loops, we store the counts in a result vector ans and return it.

### Important Concepts

Nested Loops: This approach uses nested loops to compare each element from one array with all elements from the other array. While it works for smaller inputs, it could be optimized for larger datasets using hashing or sorting.

## Notes

The code uses a brute-force approach with a time complexity of O(n \* m), where n is the size of nums1 and m is the size of nums2. This approach can be optimized for larger input sizes.

### Time Complexity

O(n \* m), where n is the size of nums1 and m is the size of nums2. Since each element of nums1 is compared to all elements of nums2 (and vice versa), this is not the most efficient solution for large inputs.

### Space Complexity

O(1) extra space, as we only use a few additional variables (firstArrCount, secondArrCount, and ans).

### Edge Cases

-   One or both arrays are empty.
-   All elements in one array are present in the other.
-   No common elements between the two arrays.
