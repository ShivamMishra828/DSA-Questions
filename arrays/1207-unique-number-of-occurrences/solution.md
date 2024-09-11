# Unique Number of Occurrences (Question 1207)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/unique-number-of-occurrences/)

Given an array of integers `arr`, write a function that returns `true` if the number of occurrences of each value in the array is unique, or `false` otherwise.

### Constraints

-   1 ≤ arr.length ≤ 1000
-   -1000 ≤ arr[i] ≤ 1000

## Solution

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> brr;  // Vector to store the occurrence counts
        sort(arr.begin(), arr.end());  // Sort the input array to count occurrences easily

        int count = 1;  // Initialize count to 1 for the first element

        // Traverse the array to count occurrences of each unique element
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {  // If current element matches previous, increment count
                count++;
            } else {
                brr.push_back(count);  // Push the count of the previous element to brr
                count = 1;  // Reset count for the next unique element
            }
        }
        brr.push_back(count);  // Push the last element's count

        sort(brr.begin(), brr.end());  // Sort the occurrence counts to check for uniqueness

        // Check if any two consecutive counts are the same
        for (int i = 0; i < brr.size() - 1; i++) {
            if (brr[i] == brr[i + 1]) {
                return false;  // If two counts are the same, return false
            }
        }

        return true;  // If no duplicate counts, return true
    }
};
```

## Explanation

-   We first sort the array to make counting occurrences easier.
-   We then traverse through the sorted array to count how many times each unique element appears and store those counts in a separate vector brr.
-   Afterward, we sort brr to easily check for any duplicate occurrence counts.
-   Finally, we iterate through brr to see if any two adjacent counts are equal. If they are, we return false. If no duplicates are found, we return true.

### Important Concepts

-   Sorting the array to group identical elements together for counting.
-   Checking the uniqueness of occurrence counts by sorting and comparing them.

### Notes

-   This approach ensures that we efficiently check for duplicate occurrences by utilizing sorting twice (once for the array and once for the occurrence counts).

### Time Complexity

-   Sorting the input array takes O(n log n).
-   Counting occurrences takes O(n).
-   Sorting the occurrence counts also takes O(n log n).
-   Overall time complexity: O(n log n).

### Space Complexity

We use an additional array brr to store the occurrence counts, which results in O(n) space complexity.

### Edge Cases

-   An array with all identical elements.
-   An array with all unique elements.
-   An array where some numbers appear multiple times and some appear only once.
