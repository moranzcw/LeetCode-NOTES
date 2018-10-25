class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        vector<int> DP(nums.size());

        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];

        DP[0] = nums[0];
        DP[1] = max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            DP[i] = max(DP[i-1],DP[i-2]+nums[i]);
        }
        return DP.back();
    }
};