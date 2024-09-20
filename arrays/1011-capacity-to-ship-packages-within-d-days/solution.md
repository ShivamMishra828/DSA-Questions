# Capacity To Ship Packages Within D Days (Question 1011)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)

Given an array `weights` representing the weight of packages and an integer `days`, find the least weight capacity of the ship that will result in all the packages being shipped within `days` days.

### Constraints

-   1 ≤ `weights.length` ≤ 50000
-   1 ≤ `weights[i]` ≤ 500
-   1 ≤ `days` ≤ weights.length

## Solution

```cpp
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // If days are greater than the number of packages, it's impossible to distribute them
        if(days > weights.size()) {
            return -1;
        }

        int s = 0, e = 0, mid = 0, ans = 0;
        int n = weights.size();

        // Calculate the initial boundaries for binary search
        // Start with the maximum single package weight as the lower bound
        // Sum of all weights as the upper bound
        for(int i = 0; i < n; i++) {
            s = max(s, weights[i]); // Ship capacity can't be less than the heaviest package
            e += weights[i];         // Upper bound: ship capacity equals the sum of all weights
        }

        // Binary search for the optimal capacity
        while(s <= e) {
            mid = s + (e - s) / 2;
            int currentWeight = 0, requiredDays = 1;

            // Check how many days are required with the current ship capacity
            for(int i = 0; i < n; i++) {
                currentWeight += weights[i];

                if(currentWeight > mid) {
                    requiredDays++;  // Start a new day of shipping
                    currentWeight = weights[i];  // Current package starts a new shipment
                }
            }

            // If the number of days required is less than or equal to the allowed days, try to minimize capacity
            if(requiredDays <= days) {
                ans = mid;  // This mid value is a possible answer
                e = mid - 1;  // Try for a smaller capacity
            } else {
                s = mid + 1;  // Increase the ship capacity as current mid can't ship within days
            }
        }

        return ans;
    }
};
```

## Explanation

-   Binary Search Setup: The idea is to perform binary search on the ship capacity. The minimum ship capacity (s) must be at least as large as the largest package in weights, and the maximum ship capacity (e) can be the sum of all the package weights.

-   Binary Search Execution: For each mid-point, simulate how many days it would take to ship all packages if the ship's capacity were mid. We increment the number of days whenever the cumulative weight for the current day exceeds the mid-point value.

-   Final Answer: We aim to find the smallest possible mid that allows all packages to be shipped within the given number of days.

### Dry Run Example

Input: weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], days = 5

1. Initial Boundaries: s = 10 (maximum single package), e = 55 (sum of all weights)

2. Mid Calculation:

-   Mid = (10 + 55)/2 = 32
-   Try capacity 32:
    -   Day 1: Ship [1, 2, 3, 4, 5, 6] (total 21)
    -   Day 2: Ship [7, 8] (total 15)
    -   Day 3: Ship [9, 10] (total 19)
    -   Total 3 days, which is within the allowed days.

3. Adjust Bounds:

    - Since 3 days <= 5 days, try smaller capacity. Update e = 31.

4. Repeat until s > e.

Final Answer: 15

### Time Complexity

-   Binary Search Time Complexity: O(log(sum of weights - max weight)).
-   Simulating Days: O(n) where n is the size of the weights array.
-   Total Complexity: O(n log(sum of weights - max weight)).

### Space Complexity

Space Complexity: O(1) as we only use a few extra variables.

### Edge Cases

-   The number of days is equal to the number of packages.
-   All packages have the same weight.
-   The minimum and maximum bounds for ship capacity differ greatly.
