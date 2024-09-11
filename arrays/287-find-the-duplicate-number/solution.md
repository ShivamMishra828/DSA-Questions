# Find the Duplicate Number (Question 287)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/find-the-duplicate-number/)

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive, there is exactly one duplicate number in `nums`. Return this duplicate number.

### Constraints

-   1 ≤ n ≤ 10^5
-   `nums` contains exactly `n + 1` integers.
-   All integers in `nums` are between `1` and `n` inclusive.
-   There is only one duplicate number in the array, but it could be repeated more than once.

## Solution

```cpp
class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int slow = 0;   // Initialize slow pointer
        int fast = 0;   // Initialize fast pointer

        // Phase 1: Detect cycle using Floyd's Tortoise and Hare
        do {
            slow = nums[slow];          // Move slow pointer by 1 step
            fast = nums[nums[fast]];    // Move fast pointer by 2 steps
        } while (slow != fast);          // Loop until slow and fast meet

        slow = 0;   // Reset slow to start for Phase 2

        // Phase 2: Find the start of the cycle
        while (slow != fast) {
            slow = nums[slow];  // Move slow by 1 step
            fast = nums[fast];  // Move fast by 1 step
        }

        return slow;  // The position where slow and fast meet is the duplicate number
    }
};
```

## Explanation

-   This solution uses Floyd’s Tortoise and Hare (Cycle Detection) algorithm.
-   The slow pointer moves one step at a time, while the fast pointer moves two steps at a time.
-   When slow equals fast, it indicates a cycle has been detected.
-   We reset the slow pointer to 0 and move both slow and fast one step at a time. The point where they meet again is the duplicate number.

### Important Concepts

-   Floyd’s Tortoise and Hare algorithm (Cycle Detection).
-   Using the cycle detection approach to find the duplicate without modifying the array or using extra space.

## Notes

-   This algorithm allows us to find the duplicate number in O(n) time without altering the array or using additional memory beyond a few pointers.
-   It leverages the fact that the array's structure can be represented as a linked list with a cycle.

### Time Complexity

O(n), where n is the number of elements in the array.

### Space Complexity

O(1), as no additional space is used other than a few variables.

### Edge Cases

-   The duplicate number appears more than once.
-   The duplicate number is the smallest or the largest number in the range.
