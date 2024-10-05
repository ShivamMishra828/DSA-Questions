# Two Sum II - Input Array Is Sorted (Question 167)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

Given a **1-indexed** array of integers `numbers` that is already **sorted in non-decreasing order**, find two numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index1]` and `numbers[index2]` where `1 <= index1 < index2 <= numbers.length`.

Return the indices of the two numbers (index1 and index2) as an integer array `[index1, index2]` of length 2.

The test cases are generated such that there is **exactly one solution**, and you may not use the same element twice.

### Constraints

-   `2 <= numbers.length <= 3 * 10^4`
-   `-1000 <= numbers[i] <= 1000`
-   `numbers` is sorted in **non-decreasing order**.
-   `-1000 <= target <= 1000`
-   The tests are generated such that there is exactly one solution.

### Solution

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int ans[] = new int[2];
        int s = 0;              // Start pointer (left)
        int e = numbers.length-1; // End pointer (right)

        while(s < e) {
            if(numbers[s] + numbers[e] == target) { // If target is found
                ans[0] = s + 1; // Since array is 1-indexed, return s+1
                ans[1] = e + 1; // Since array is 1-indexed, return e+1
                return ans;
            }
            else if(numbers[s] + numbers[e] > target) { // If sum is greater than target, move the end pointer left
                e--;
            }
            else { // If sum is less than target, move the start pointer right
                s++;
            }
        }
        return ans;
    }
}
```

## Explanation

1. Two Pointers Technique:

-   Since the array is sorted, we can use a two-pointer approach to find the target sum.
-   We initialize two pointers:
    -   s (start pointer) at the beginning of the array.
    -   e (end pointer) at the end of the array.
-   We check the sum of numbers[s] + numbers[e].
    -   If the sum is equal to the target, return the indices (1-indexed).
    -   If the sum is greater than the target, move the end pointer e leftward to decrease the sum.
    -   If the sum is less than the target, move the start pointer s rightward to increase the sum.

2. 1-Indexed Output:

-   Since the output needs to be 1-indexed (not 0-indexed like arrays in Java), we return s + 1 and e + 1 when the target is found.

### Time Complexity

O(n): We only pass through the array once using two pointers (s and e), and each pointer moves at most n times.

### Space Complexity

O(1): We use only a constant amount of extra space for the answer array.

### Dry Run

Input: numbers = [2, 7, 11, 15], target = 9

Execution Steps
1.Initialize s = 0, e = 3

-   numbers[s] + numbers[e] = 2 + 15 = 17, which is greater than 9. Move e to 2.

2. Now s = 0, e = 2

-   numbers[s] + numbers[e] = 2 + 11 = 13, which is greater than 9. Move e to 1.

3. Now s = 0, e = 1

-   numbers[s] + numbers[e] = 2 + 7 = 9, which matches the target.

4. Return [s + 1, e + 1] = [1, 2].

Output:- [1, 2]
