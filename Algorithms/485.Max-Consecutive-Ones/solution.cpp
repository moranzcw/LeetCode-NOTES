class Solution 
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int max = 0,temp=0;;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 1)
                temp++;
            else
            {
                if(temp>max)
                    max = temp;
                temp = 0;
            }
        }
        if(temp>max)
            max = temp;
        return max;
    }
};