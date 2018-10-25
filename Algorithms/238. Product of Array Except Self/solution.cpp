class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> result(nums.size(),0);
        result[nums.size()-1] = 1;
        for(int i=nums.size()-2;i>=0;i--)
            result[i] = result[i+1]*nums[i+1];
        int left=1;
        for(int i=1;i<nums.size();i++)
        {
            left *= nums[i-1];
            result[i] *= left;
        }
        return result;
    }
};