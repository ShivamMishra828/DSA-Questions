class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        int currSum = 0;
        int l = 0, r = 0;
        int ans = Integer.MAX_VALUE;

        while(r < n) {
            currSum += nums[r];
            while(currSum >= target) {
                currSum -= nums[l];
                ans = Math.min(r-l+1, ans);
                l++;
            }
            r++;
        }
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }
}