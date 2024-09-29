# Trapping Rain Water (Question 42)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/trapping-rain-water/)

Given `n` non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

### Constraints

-   `n == height.length`
-   1 ≤ `n` ≤ 2 \* 10^4
-   0 ≤ `height[i]` ≤ 10^5

## Solution

```java
class Solution {

    // Function to calculate the maximum height to the left of each element
    public static void findLeftMax(int arr[], int lMaxArr[]) {
        int max = arr[0];  // Initialize max with the first element
        lMaxArr[0] = arr[0];  // First element is its own max
        for(int i = 1; i < arr.length; i++) {
            if(arr[i] > max) {
                lMaxArr[i] = arr[i];  // Update the left max if the current element is greater
                max = arr[i];  // Update the current max value
            } else {
                lMaxArr[i] = max;  // Use the previous max if current element is smaller
            }
        }
    }

    // Function to calculate the maximum height to the right of each element
    public static void findRightMax(int arr[], int rMaxArr[]) {
        int max = arr[arr.length-1];  // Initialize max with the last element
        rMaxArr[arr.length-1] = arr[arr.length-1];  // Last element is its own max
        for(int i = arr.length-2; i >= 0; i--) {
            if(arr[i] > max) {
                rMaxArr[i] = arr[i];  // Update the right max if the current element is greater
                max = arr[i];  // Update the current max value
            } else {
                rMaxArr[i] = max;  // Use the previous max if current element is smaller
            }
        }
    }

    // Main function to calculate the trapped water
    public int trap(int[] arr) {
        int n = arr.length;
        int lMaxArr[] = new int[n];  // Array to store the left max of each element
        int rMaxArr[] = new int[n];  // Array to store the right max of each element
        findLeftMax(arr, lMaxArr);  // Calculate left max for all elements
        findRightMax(arr, rMaxArr);  // Calculate right max for all elements
        int trappedWater = 0;  // Variable to accumulate the total trapped water

        // Edge case: No water can be trapped if there are less than 3 bars
        if(n <= 2) {
            return trappedWater;
        }

        // Calculate trapped water for each element
        for(int i = 0; i < n; i++) {
            int waterAtIndex = Math.min(lMaxArr[i], rMaxArr[i]) - arr[i];
            trappedWater += waterAtIndex;  // Add trapped water for current element
        }

        return trappedWater;  // Return the total trapped water
    }
}
```

## Explanation

-   Left Max Array (lMaxArr): This array stores the maximum height of the bars to the left of each index, including the current index.
-   Right Max Array (rMaxArr): Similarly, this array stores the maximum height of the bars to the right of each index.
-   For each index i, the trapped water is determined by the minimum of the left and right max heights at that index minus the height of the bar at index i.
-   The total trapped water is calculated by summing the water trapped at each index.

### Important Concepts

-   Two-Pass Solution: We first calculate the lMaxArr and rMaxArr in two separate passes through the array, and then compute the trapped water in a third pass.
-   Efficient Calculation: This method ensures that we only traverse the array three times, making the solution efficient even for larger arrays.

### Time Complexity

O(n) for calculating the lMaxArr, rMaxArr, and the trapped water in three separate loops, where n is the length of the array.

### Space Complexity

O(n) for the additional arrays (lMaxArr and rMaxArr) used to store the left and right max values.

### Edge Cases

-   If there are fewer than three bars, no water can be trapped, so the function returns 0.
-   If the elevation map is flat (all bars have the same height), no water can be trapped.

### Dry Run

Input: arr = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]

1. Left Max Calculation:

-   lMaxArr = [0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3]

2. Right Max Calculation:

-   rMaxArr = [3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1]

3. Trapped Water Calculation:

-   For each index, calculate min(lMaxArr[i], rMaxArr[i]) - arr[i].
-   trappedWater = 6 units.

Final Answer: 6 units of water can be trapped.
