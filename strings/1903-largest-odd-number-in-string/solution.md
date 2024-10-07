# 1903. Largest Odd Number in String

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/largest-odd-number-in-string/)

Given a string `s`, which represents a large integer, return the **largest-valued odd** integer (as a substring) that is a non-empty prefix of `s`. If no odd integer exists, return an empty string `""`.

### Solution

```java
class Solution {
    public String largestOddNumber(String s) {
        // Iterate through the string from the end to the start
        for(int i = s.length() - 1; i >= 0; i--) {
            // Get the ASCII value of the character and convert it to an integer
            int num = s.charAt(i) + 0;

            // Check if the number is odd using bitwise AND operation
            if((num & 1) != 0) {
                // If odd, return the substring from the start to the current index
                return s.substring(0, i + 1);
            }
        }
        // If no odd number is found, return an empty string
        return "";
    }
}
```

## Explanation

Step-by-Step Breakdown:

1. Iterate from End to Start:

-   Loop through the string s from the last character to the first.
-   Start checking from the end because we're looking for the largest odd number, and removing even digits from the end makes the number smaller.

2. Check if the Character Represents an Odd Number:

-   s.charAt(i) + 0 gives the ASCII value of the character. By adding 0, it converts the character to its corresponding integer.
-   Use (num & 1) != 0 to check if the number is odd:
    -   Bitwise & 1 checks the least significant bit, which is 1 for odd numbers and 0 for even numbers.

3. Return the Substring:

-   If an odd number is found, return the substring from the start of s to the current index i + 1.

4. Return an Empty String if No Odd Number is Found:

-   If the loop completes without finding an odd number, return "" because no odd numbers exist in s.

### Time Complexity

O(n): We iterate through the string at most once, where n is the length of the string s.

### Space Complexity

O(1): No extra data structures are used, and only a few variables are needed for calculations.

### Dry Run

Input:- s = "3542";

### Execution Steps

1. Start iterating from the last character:

-   i = 3, num = '2' (even).
-   i = 2, num = '4' (even).
-   i = 1, num = '5' (odd).
-   Return s.substring(0, 2) which is "35".

Output:- "35"
