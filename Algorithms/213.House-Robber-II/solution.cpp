class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for(int i=2;i<nums.size()-1;i++){
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }
        
        int max1 = dp[nums.size()-2];
        
        dp[1] = nums[1];
        dp[2] = max(nums[1],nums[2]);
        
        for(int i=3;i<nums.size();i++){
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }
        
        int max2 = dp[nums.size()-1];
        
        return max(max1, max2);
        
    }
}; 