class Solution 
{
public:
    int minMoves(vector<int>& nums) 
    {
        int min = nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] < min)
                min = nums[i];
        }
        int steps=0;
        for(int i=0;i<nums.size();i++)
        {
            steps += nums[i]-min;
        }
        return steps;
    }
};