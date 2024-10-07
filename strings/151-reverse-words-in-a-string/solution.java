class Solution {
    public String reverseWords(String str) {
        str = str.trim(); // Trim leading/trailing spaces
        String[] words = str.split("\\s+"); // Split on one or more spaces
        String result = "";

        for (int i = words.length - 1; i >= 0; i--) {
            result += words[i];
            if (i > 0) {
                result += " ";
            }
        }

        return result;
    }
}