class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int arr[] = new int[26];
        Arrays.fill(arr, -1);
        int max = -1;

        for(int i = 0; i<s.length(); i++) {
            char ch = s.charAt(i);

            if(arr[ch - 'a'] == -1) arr[ch-'a'] = i;
            else max = Math.max(max, i-arr[ch-'a']-1);
        }
        return max;
    }
}