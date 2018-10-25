class Solution 
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int XOR = 0;
        for(int i=0;i<nums.size();i++)
            XOR ^= nums[i];
            
        int one = 1;
        while( (one & XOR) == 0)
            one = one << 1;
            
        vector<int> result(2,0);
        for(int i=0;i<nums.size();i++)
        {
            if( (one & nums[i]) == 0)
                result[0] ^= nums[i];
            else
                result[1] ^= nums[i];
        }
        return result;
    }
};