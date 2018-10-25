class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        set<int> S;
        for(int i=0;i<nums.size();i++)
        {
            if(S.count(nums[i])>0)
                S.erase(nums[i]);
            else
                S.insert(nums[i]);
        }
        return *S.begin();
    }
};