# 1624. Largest Substring Between Two Equal Characters

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/largest-substring-between-two-equal-characters/)

Given a string `s`, return the length of the largest substring between two equal characters, excluding the characters themselves. If there is no such substring, return `-1`.

### Solution

```java
class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        // Create an array to store the first occurrence index of each character
        int arr[] = new int[26];
        Arrays.fill(arr, -1); // Initialize the array with -1
        int max = -1; // Initialize the max length as -1 (for the case where no valid substrings exist)

        // Traverse the string
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i); // Get the current character

            // If this is the first occurrence of the character
            if (arr[ch - 'a'] == -1) {
                arr[ch - 'a'] = i; // Store its index
            }
            // If the character has been seen before
            else {
                // Calculate the length between the current index and the stored index
                max = Math.max(max, i - arr[ch - 'a'] - 1);
            }
        }
        return max; // Return the maximum length found
    }
}
```

## Explanation

Step-by-Step Breakdown:

1. Initialize Array:

-   arr is an array of size 26 (for all lowercase letters 'a' to 'z'), initialized to -1. It keeps track of the first occurrence of each character.
-   max is set to -1 to handle the case where no valid substring is found.

2. Traverse the String:

-   For each character in the string, calculate its index ch - 'a' to map it to the arr.
-   If the character is seen for the first time (arr[ch - 'a'] == -1), store its index in arr.
-   If the character has been seen before, calculate the distance between the current index i and the stored index, then update max with the larger of the current max and this distance.

3. Return Result:

-   After processing all characters, return max, which contains the length of the largest valid substring.

### Time Complexity

O(n): We iterate through the string once, and operations within the loop are constant time.

### Space Complexity

O(1): The array arr has a fixed size of 26, independent of the input size.

### Dry Run

Input:- s = "abca"

Execution Steps

1. arr = [-1, -1, -1, ..., -1] (size 26)

2. max = -1

3. Iteration over the string:

-   i = 0, ch = 'a':
    -   arr[0] == -1 (first occurrence), so store arr[0] = 0.
-   i = 1, ch = 'b':
    -   arr[1] == -1 (first occurrence), so store arr[1] = 1.
-   i = 2, ch = 'c':
    -   arr[2] == -1 (first occurrence), so store arr[2] = 2.
-   i = 3, ch = 'a':
    -   arr[0] == 0 (already occurred), calculate distance: 3 - 0 - 1 = 2.
    -   Update max = 2.

4. Final value of max = 2.

Output:- 2
