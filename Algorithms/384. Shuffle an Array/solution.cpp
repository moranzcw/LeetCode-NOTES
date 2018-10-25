class Solution 
{
public:
    vector<int> nums;
    Solution(vector<int> nums):nums(nums) 
    {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() 
    {
        return this->nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() 
    {
        vector<int> shuffle(nums);
        int pos;
        for(int i=0;i<shuffle.size();i++)
        {
            pos = rand()%(shuffle.size()-i) + i;
            swap(shuffle[i],shuffle[pos]);
        }
        return shuffle;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */