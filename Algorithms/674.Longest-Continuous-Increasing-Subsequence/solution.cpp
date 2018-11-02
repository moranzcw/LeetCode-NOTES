class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int max = 1;
        int temp = 1;
        int last = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] > last){
                temp += 1;
                if(temp > max)
                    max = temp;
            }
            else{
                temp = 1;
            }
            last = nums[i];
        }
        return max;
    }
};