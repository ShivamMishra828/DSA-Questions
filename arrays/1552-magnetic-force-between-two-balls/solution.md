# Magnetic Force Between Two Balls (Question 1552)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/magnetic-force-between-two-balls/)

You are given an array `position` representing the positions of balls in a straight line, and an integer `m` representing the number of balls to place. You want to place the `m` balls such that the minimum magnetic force between any two balls is as large as possible. Return the largest minimum magnetic force.

### Constraints

-   2 ≤ `m` ≤ `position.length` ≤ 10^5
-   1 ≤ `position[i]` ≤ 10^9

## Solution

```cpp
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int s = 1, e, mid, ans;
        // Sort the positions to facilitate binary search
        sort(position.begin(), position.end());
        int n = position.size();
        e = position[n - 1] - position[0];  // Maximum possible distance (furthest apart)

        // Binary search to find the largest minimum force
        while (s <= e) {
            mid = s + (e - s) / 2;  // Middle distance (force) to check

            // Place the first ball at the first position
            int count = 1, last_position = position[0];

            // Try placing the remaining m-1 balls with at least `mid` distance between them
            for (int i = 1; i < n; i++) {
                if (position[i] - last_position >= mid) {
                    count++;
                    last_position = position[i];
                }
            }

            // If we can place at least m balls, try for a larger distance
            if (count >= m) {
                ans = mid;  // This is a valid configuration
                s = mid + 1;  // Try to find a larger minimum distance
            } else {
                e = mid - 1;  // Decrease the distance
            }
        }
        return ans;
    }
};
```

## Explanation

1. Sorting the Positions: We first sort the position array to facilitate easier ball placement.

2. Binary Search on Distance:

    - We perform a binary search on the possible values of minimum magnetic force, where s = 1 (minimum possible force) and e = position[n-1] - position[0] (maximum possible force).
    - For each mid-point (mid), we check if we can place all m balls such that the minimum distance between any two consecutive balls is at least mid.

3. Ball Placement:

    - Starting with the first ball at position[0], we try to place subsequent balls in such a way that the distance between the current ball and the last placed ball is at least mid.

4. Adjusting the Search Space:

    - If it is possible to place all m balls with a minimum distance of mid, we store this value in ans and attempt to find a larger distance by updating s = mid + 1.
    - If it is not possible, we reduce the search space by setting e = mid - 1.

5. Final Answer: Once the binary search completes, ans holds the largest minimum distance at which the balls can be placed.

### Dry Run Example

Input: position = [1, 2, 8, 4, 9], m = 3

1. Sort the Positions: [1, 2, 4, 8, 9]

2. Initial Boundaries:

    - s = 1 (minimum possible distance)
    - e = 8 (maximum possible distance)

3. First Mid: mid = (1 + 8) / 2 = 4

    - Place the first ball at position 1.
    - Next ball placed at position 8 (distance = 8 - 1 = 7 ≥ 4).
    - Third ball placed at position 9 (distance = 9 - 8 = 1).
    - We successfully placed 3 balls. Update ans = 4 and try a larger distance by setting s = 5.

4. Next Mid: mid = (5 + 8) / 2 = 6

    - Place the first ball at position 1.
    - Next ball placed at position 8 (distance = 7 ≥ 6).
    - Unable to place a third ball. So, reduce the search space by setting e = 5.

5. Next Mid: mid = (5 + 5) / 2 = 5

    - Similar process as before, place 3 balls successfully.
    - Update ans = 5 and try a larger distance by setting s = 6.

6. Final Answer: ans = 3.

### Time Complexity

-   Sorting: O(n log n) where n is the length of position.
-   Binary Search: O(log(max position - min position)).
-   Placing Balls: O(n) for each iteration of the binary search.
-   Overall: O(n log n).

### Space Complexity

O(1): Apart from the input and output arrays, no extra space is used.

### Edge Cases

-   Only 2 positions, minimum possible m.
-   All positions are identical.
