class Solution 
{
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int length = nums.size()+1;
        int startIndex = 0, endIndex = 0;
        int sum = 0;
        while(endIndex < nums.size())
        {
            while(endIndex < nums.size() && sum < s)
            {
                sum += nums[endIndex];
                endIndex += 1;
            }
            while(startIndex < endIndex && sum >= s)
            {
                if( sum >= s)
                    length = min(length,endIndex - startIndex);
                sum -= nums[startIndex];
                startIndex += 1;
            }
        }
        return length <= nums.size()? length:0;
    }
};