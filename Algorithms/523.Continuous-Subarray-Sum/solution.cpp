class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        bool flag = false;
        if(k==0)
            flag = true;
        vector<int> dp(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            int sum = nums[i];
            for(int j=i+1;j<nums.size();j++){
                sum += nums[j];
                if(flag){
                    if(sum - k == 0)
                        return true;
                }
                else{
                    if (sum % k == 0)
                    return true;
                }
            }
        }
        return false;
    }
};
