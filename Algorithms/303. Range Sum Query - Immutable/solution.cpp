class NumArray 
{
public:
    vector<int> sums;
    NumArray(vector<int> &nums) 
    {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            sums.push_back(sum);
        }
    }

    int sumRange(int i, int j) 
    {
        if(i>0)
            return sums[j] - sums[i-1];
        return sums[j];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);