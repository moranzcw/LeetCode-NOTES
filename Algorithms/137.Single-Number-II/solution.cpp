class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        multiset<int> S;
        for(int i=0;i<nums.size();i++)
        {
            if(S.count(nums[i])>1)
                S.erase(nums[i]);
            else
                S.insert(nums[i]);
        }
        return *S.begin();
    }
};