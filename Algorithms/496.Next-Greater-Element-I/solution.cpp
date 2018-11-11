class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int, int> max;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j] > nums[i]){
                    max[nums[i]] = nums[j];
                    break;
                }
            }
        }
        
        vector<int> result(findNums.size(),0);
        for(int i=0;i<findNums.size();i++){
            if(max.find(findNums[i]) == max.end()){
                result[i] = -1;
            }else
                result[i] = max[findNums[i]];
        }
        return result;
    }
};
