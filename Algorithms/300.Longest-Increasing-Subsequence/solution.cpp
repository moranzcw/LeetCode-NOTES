class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {        
        int maxlen = 0;
        
        vector<int> dp(nums.size());
        for(int i=0;i<nums.size();i++){
            int max_dp = 0;
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j])
                    max_dp = max(dp[j], max_dp);
            }
            dp[i] = max_dp + 1;
            maxlen = max(dp[i], maxlen);
        }
        return maxlen;
    }
};
