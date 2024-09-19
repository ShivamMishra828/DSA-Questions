# Find K Closest Elements (Question 658)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/find-k-closest-elements/)

Given a sorted array `arr`, two integers `k` and `x`, the task is to find the `k` closest integers to `x` in the array. The result should be sorted in ascending order. If there's a tie, the smaller element is preferred.

### Constraints

-   1 <= k <= arr.length
-   1 <= arr.length <= 10^4
-   -10^4 <= arr[i], x <= 10^4
-   arr is sorted in non-decreasing order.

## Solution

```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0; // Start of the window
        int j = arr.size()-1; // End of the window
        vector<int> ans;

        // Shrinking the window while the number of elements between i and j is greater than k
        while (j - i >= k) {
            // If the element at the start is further from x than the element at the end, move the start pointer
            if ((x - arr[i]) > (arr[j] - x)) {
                i++;  // The left element is farther, so we increment the start pointer
            } else {
                j--;  // The right element is farther, so we decrement the end pointer
            }
        }

        // Collect the k closest elements from index i to j
        for (int m = i; m <= j; m++) {
            ans.push_back(arr[m]);
        }

        return ans;
    }
};
```

## Explanation

-   We maintain two pointers i and j which initially point to the start and end of the array respectively.
-   The idea is to gradually shrink the window of elements between i and j to contain exactly k elements.
-   In each iteration, we compare the absolute difference between x and the elements at i and j. If the element at i is farther from x, we increment i. If the element at j is farther, we decrement j.
-   Once i and j are exactly k elements apart, we return the subarray between i and j.

### Important Concepts

-   Two-pointer technique: This approach ensures that we find the k closest elements by shrinking the window between two pointers.
-   Absolute difference: We compare the absolute differences between x and the elements at both ends to decide which element to discard.

### Dry Run Example

Input: arr = [1, 2, 3, 4, 5], k = 4, x = 3

Initial state:

i = 0, j = 4, k = 4, x = 3
arr[i] = 1, arr[j] = 5
Step 1: Compare |3 - 1| (which is 2) and |5 - 3| (which is 2). Since both are equal, we prefer the smaller element, so decrement j.

i = 0, j = 3
Final result: The window is now [i, j] = [0, 3] which gives [1, 2, 3, 4]. The result is [1, 2, 3, 4].

### Time Complexity

-   Time Complexity: The while loop runs in O(n - k), where n is the size of the array. Pushing elements into the result vector takes O(k). Thus, the overall time complexity is O(n).
-   Space Complexity: O(k) for storing the result.

### Edge Cases

-   k equals the size of the array (output the entire array).
-   All elements are the same.
-   The target x is smaller or larger than all elements in the array.
