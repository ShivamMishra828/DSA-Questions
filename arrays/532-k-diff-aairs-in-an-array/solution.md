# K-diff Pairs in an Array (Question 532)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/k-diff-pairs-in-an-array/)

Given an array of integers and an integer `k`, find the number of unique k-diff pairs in the array. A k-diff pair is an integer pair `(nums[i], nums[j])`, where:

-   `|nums[i] - nums[j]| = k`
-   `i != j`

### Constraints

-   The array can contain duplicates.
-   0 ≤ k ≤ 10^7

## Solution

```cpp
class Solution {
public:
    // Binary search to find the target value in the sorted array
    bool binarySearch(int s, int e, int target, vector<int>& nums) {
        int mid = s + (e - s) / 2;
        // Perform binary search in the range [s, e]
        while(s <= e) {
            if(nums[mid] == target) {
                return true;  // Found target
            } else if(nums[mid] > target) {
                e = mid - 1;  // Search the left half
            } else {
                s = mid + 1;  // Search the right half
            }
            mid = s + (e - s) / 2;
        }
        return false;  // Target not found
    }

    int findPairs(vector<int>& nums, int k) {
        // Sort the array to make it easier to find pairs
        sort(nums.begin(), nums.end());
        int i = 0;
        int ans = 0;

        // Traverse the array and find unique k-diff pairs
        while(i < nums.size() - 1) {
            int target = k + nums[i];  // Calculate the target value that forms a k-diff pair
            if(binarySearch(i + 1, nums.size() - 1, target, nums)) {
                ans++;  // Increment count if pair is found
            }
            // Skip duplicates in the array to ensure unique pairs
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
            i++;  // Move to the next element
        }
        return ans;  // Return total number of unique k-diff pairs
    }
};
```

## Explanation

1. Sorting:
   First, the array is sorted to make it easier to find pairs using binary search. Sorting allows us to check for the presence of the target element in a sorted portion of the array.

2. Binary Search:
   For each element in the sorted array, we compute the target (target = k + nums[i]) and use binary search to check if the target exists in the rest of the array. This approach helps reduce time complexity compared to a brute-force search.

3. Avoiding Duplicates:
   After finding a k-diff pair for an element, we skip any duplicate elements to ensure we only count unique pairs.

4. Binary Search Function:
   The binarySearch function performs a standard binary search to find the target in the subarray nums[i+1] to nums[size-1]. If it finds the target, it returns true; otherwise, it returns false.

## Dry Run Example

For the input array: [3, 1, 4, 1, 5] and k = 2:

1. Initial Array:
   [3, 1, 4, 1, 5]

2. Sort the Array:
   [1, 1, 3, 4, 5]

3. Start Traversing:

-   i = 0:
    -   nums[i] = 1, target = 1 + 2 = 3
    -   Perform binary search in [1, 3, 4, 5] → Found → ans = 1
-   Skip duplicate nums[1] = 1

-   i = 2:

    -   nums[i] = 3, target = 3 + 2 = 5
    -   Perform binary search in [4, 5] → Found → ans = 2

-   i = 3:

    -   nums[i] = 4, target = 4 + 2 = 6
    -   Perform binary search in [5] → Not Found

-   i = 4:

    -   nums[i] = 5, no need to search further since it's the last element.

4. Final Answer:
   ans = 2 (the pairs are (1, 3) and (3, 5))

### Time Complexity

-   Sorting takes O(n log n).
-   Binary search for each element takes O(log n), and we perform it for each element in the array.
-   Overall, the time complexity is O(n log n).

### Space Complexity

O(1) additional space, assuming sorting is done in place.
