class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        vector<bool>table(nums.size(), false);
        table[0] = true;
        
        for(auto i = 1; i < nums.size(); ++i)
        {
            for(auto j = 0; j < i; ++j)
            {
                if (table[j] && nums[j] >= i - j)
                {
                    table[i] = true;
                    break;
                }
            }
        }
        
        return table[nums.size() - 1];
        
    }
};
