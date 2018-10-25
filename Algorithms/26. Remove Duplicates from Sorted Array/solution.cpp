class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int length = nums.size();
        for(int i=0,j=1;j<nums.size();j++)
        {
            if(nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
            else
                length--;
        }
        return length;
    }
};