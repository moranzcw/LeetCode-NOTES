class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector <int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] *= -1;
            }
            else {
                ans.push_back(index + 1);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};