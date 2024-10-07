# 151. Reverse Words in a String

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/reverse-words-in-a-string/)

Given an input string `str`, reverse the order of the words. A word is defined as a sequence of non-space characters. The words in `str` will be separated by at least one space.

Return a string of the words in reverse order, concatenated by a single space.

### Solution

```java
class Solution {
    public String reverseWords(String str) {
        // Step 1: Remove leading and trailing spaces
        str = str.trim();

        // Step 2: Split the string based on one or more spaces
        String[] words = str.split("\\s+");

        // Step 3: Initialize an empty string to store the result
        String result = "";

        // Step 4: Iterate over the words array in reverse order
        for (int i = words.length - 1; i >= 0; i--) {
            result += words[i];
            // Step 5: Add a space between words (but not after the last word)
            if (i > 0) {
                result += " ";
            }
        }

        // Step 6: Return the final result
        return result;
    }
}
```

## Explanation

Step-by-Step Breakdown:

1. Trim the Input String:

-   str.trim() removes any leading or trailing spaces from the input string.

2. Split the String:

-   str.split("\\s+") splits the string into words based on one or more spaces.

3. Initialize Result String:

-   String result will hold the reversed words.

4. Iterate in Reverse Order:

-   Loop through the words array in reverse order and concatenate each word to the result string.
-   Add a space after each word except for the last one to ensure proper spacing.

5. Return the Result:

-   Return the result string, which contains the words in reverse order.

### Time Complexity

O(n): Trimming, splitting, and joining the words all take time proportional to the length of the input string.

### Space Complexity

O(n): The space is used to store the array of words and the result string.

### Dry Run

Input:- "the sky is blue "

Execution Steps

1. Trim:

-   str becomes "the sky is blue".

2. Split:

-   words = ["the", "sky", "is", "blue"].

3. Reverse and Build Result:

-   Iterate from the last word to the first:
    -   result = "blue".
    -   result = "blue is".
    -   result = "blue is sky".
    -   result = "blue is sky the".

4. Return:

-   result = "blue is sky the".

Output:- "blue is sky the"
