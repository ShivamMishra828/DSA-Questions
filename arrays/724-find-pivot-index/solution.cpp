class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        int lsum = 0;
        int rsum = 0;
        int totalSum = 0;
        for(int i = 0; i<nums.size(); i++){
            totalSum += nums[i];
        }

        for(int i = 0; i<nums.size(); i++) {
            rsum = totalSum - lsum - nums[i];            
            if(lsum == rsum) {
                return i;
            }
            else {
                lsum += nums[i];
            }
        }
        return -1;
    }
};