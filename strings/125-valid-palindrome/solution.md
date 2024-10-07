# 125. Valid Palindrome

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/valid-palindrome/)

Given a string `s`, return `true` if it is a **palindrome**, or `false` otherwise. A string is a palindrome when it reads the same forward and backward, ignoring case and considering only alphanumeric characters.

### Solution

```java
class Solution {
    public boolean isPalindrome(String s) {
        // If string length is less than 2, it is trivially a palindrome
        if(s.length() < 2) {
            return true;
        }

        // Initialize two pointers, i starting at the beginning, j at the end
        int i = 0;
        int j = s.length() - 1;

        // Process the string while pointers haven't crossed each other
        while(i < j) {
            char firstChar = s.charAt(i); // Character at the left pointer
            char lastChar = s.charAt(j);  // Character at the right pointer

            // Ignore non-alphanumeric characters from the left
            if(!Character.isLetterOrDigit(firstChar)) {
                i++;
            }
            // Ignore non-alphanumeric characters from the right
            else if(!Character.isLetterOrDigit(lastChar)) {
                j--;
            }
            // Compare valid alphanumeric characters, ignoring case
            else {
                if(Character.toLowerCase(firstChar) != Character.toLowerCase(lastChar)) {
                    return false; // If they don't match, it's not a palindrome
                }
                i++; // Move left pointer to the right
                j--; // Move right pointer to the left
            }
        }
        return true; // If all characters match, the string is a palindrome
    }
}
```

## Explanation

Step-by-Step Breakdown:

1. Edge Case Check:

-   If the string is shorter than 2 characters, it is trivially a palindrome, so return true.

2. Two Pointers:

-   Initialize two pointers, i starting at the beginning of the string, and j starting at the end.

3. Ignore Non-Alphanumeric Characters:

-   The problem requires ignoring any non-alphanumeric characters. This is handled by the conditions where if the character is not alphanumeric, increment or decrement the pointers without comparing.

4. Compare Characters:

-   If both characters are alphanumeric, they are compared after converting them to lowercase to ensure case insensitivity.

5. Return Result:

-   If all valid characters match, return true, meaning the string is a palindrome. If any characters do not match, return false.

### Time Complexity

O(n): We traverse the string from both ends, skipping over non-alphanumeric characters and comparing the rest. Each character is visited at most once.

### Space Complexity

O(1): The algorithm only uses a fixed amount of space for the pointers and variables, regardless of the size of the input.

### Dry Run

Input:- s = "A man, a plan, a canal: Panama"

Execution Steps

1. i = 0, j = 29, characters s[0] = 'A' and s[29] = 'a' are alphanumeric and match after case normalization.

-   Increment i to 1, decrement j to 28.

2. i = 1, j = 28, characters s[1] = ' ' (space) is not alphanumeric.

-   Increment i to 2.

3. i = 2, j = 28, characters s[2] = 'm' and s[28] = 'm' match.

-   Increment i to 3, decrement j to 27.

... continue this process ...
At the end, the function will return true because all characters match after processing alphanumeric ones.

Output:- true

### Edge Cases

1. Empty string or string of one character:

-   "" or "a" should return true.

2. String with only special characters:

-   "!!!", "#@" should return true.

3. Case insensitivity:

-   Strings like "RaceCar", "rAceCaR" should return true.
