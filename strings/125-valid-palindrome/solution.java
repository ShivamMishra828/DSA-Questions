class Solution {
    public boolean isPalindrome(String s) {
        if(s.length() < 2) {
            return true;
        }
        int i = 0;
        int j = s.length()-1;
        while(i < j) {
            char firstChar = s.charAt(i);
            char lastChar = s.charAt(j);
            if(!Character.isLetterOrDigit(firstChar)) {
                i++;
            }
            else if(!Character.isLetterOrDigit(lastChar)) {
                j--;
            }
            else {
                if(Character.toLowerCase(firstChar) != Character.toLowerCase(lastChar)) {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
}