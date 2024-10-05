# Boats to Save People (Question 881)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/boats-to-save-people/)

You are given an array `people` where `people[i]` represents the weight of the `i-th` person, and an integer `limit` represents the maximum weight that a boat can carry. Each boat can carry at most two people at the same time, provided the sum of their weights is at most `limit`.

Return the minimum number of boats to carry every given person.

### Constraints:

-   `1 <= people.length <= 5 * 10^4`
-   `1 <= people[i] <= limit <= 3 * 10^4`

### Solution

```java
class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people); // Sort the array of people by weight
        int s = 0; // Start pointer (lightest person)
        int e = people.length - 1; // End pointer (heaviest person)
        int count = 0; // Count of boats used

        while (s <= e) {
            if (people[s] + people[e] <= limit) { // If lightest and heaviest can share a boat
                s++; // Move the start pointer (lightest person gets on a boat)
            }
            e--; // The heaviest person always gets on a boat
            count++; // Increment the boat count
        }

        return count; // Return total boats needed
    }
}
```

## Explanation

1. Sorting:

-   First, sort the array people in non-decreasing order. This allows us to use a two-pointer approach effectively.

2. Two Pointer Technique:

-   Initialize two pointers:
    -   s (start) at the beginning (lightest person).
    -   e (end) at the end (heaviest person).
-   Try to pair the lightest and heaviest people.
    -   If their combined weight is less than or equal to the limit, place both on the same boat (increment s and decrement e).
    -   Otherwise, place only the heaviest person on a boat (decrement e).
-   Continue until all people are placed on boats, counting the number of boats used.

3. Boat Count:

-   Each iteration places at least one person on a boat, so increment the boat count in every iteration.

### Time Complexity

O(n log n): Sorting the people array takes O(n log n), and the two-pointer pass through the array takes O(n).

### Space Complexity

O(1): We only use a constant amount of extra space (aside from the input array).

### Dry Run

Input:- people = [3, 5, 3, 4], limit = 5

Execution Steps

1. Sort the array: people = [3, 3, 4, 5]

2. Initialize s = 0, e = 3, count = 0.

3. First boat:

-   people[s] + people[e] = 3 + 5 = 8 (too heavy), so put people[e] (5) on a boat.
-   Move e to 2, increment count to 1.

4. Second boat:

-   people[s] + people[e] = 3 + 4 = 7 (too heavy), so put people[e] (4) on a boat.
-   Move e to 1, increment count to 2.

5. Third boat:

-   people[s] + people[e] = 3 + 3 = 6 (fits), so put both people[s] and people[e] on the same boat.
-   Move s to 1, e to 0, increment count to 3.

6. All people are placed on boats, return count = 3.

Output:- 3
