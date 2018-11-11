class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> max;
        for(int i=0;i<nums.size();i++){
            int find = false;
            for(int j=(i+1)%nums.size();j!=i;j=(j+1)%nums.size()){
                if(nums[j] > nums[i]){
                    max.push_back(nums[j]);
                    find = true;
                    break;
                }
            }
            if(!find)
                max.push_back( -1);
        }
        return max;
    }
};
