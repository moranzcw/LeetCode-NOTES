class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int> > result;
        if(nums.size() == 0)
            return result;

        sort(nums.begin(),nums.end());

        for( int pos1 = 0;pos1<nums.size();pos1++)
        {
            for(int pos2 = pos1 + 1;pos2<nums.size();pos2++)
            {
                for(int pos3 = pos2 + 1, pos4 = nums.size() - 1; pos3 < pos4;)
                {
                    int sum = nums[pos1] + nums[pos2] + nums[pos3] + nums[pos4];
                    if(sum == target)
                    {
                            vector<int> tempResult;
                            tempResult.push_back(nums[pos1]);
                            tempResult.push_back(nums[pos2]);
                            tempResult.push_back(nums[pos3]);
                            tempResult.push_back(nums[pos4]);
                            result.push_back(tempResult);
    
                            while( pos3+1 < pos4 && nums[pos3+1] == nums[pos3])
                                pos3++;
                            pos3++;
                            
                            while( pos4-1 > pos3 && nums[pos4-1] == nums[pos4])
                                pos4--;
                            pos4--;
                    }
                    else if(sum < target)
                        pos3++;
                    else
                        pos4--;
                }
                while( pos2+1 < nums.size() && nums[pos2+1] == nums[pos2])
                    pos2++;
            }
            while( pos1+1 < nums.size() && nums[pos1+1] == nums[pos1])
                    pos1++;
        }
        return result;
    }
};
