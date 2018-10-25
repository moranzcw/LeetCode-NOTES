class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int left=0,right=numbers.size()-1;
        while(numbers[left]+numbers[right] != target)
        {
            if(numbers[left]+numbers[right] < target)
                left++;
            else
                right--;
        }
        vector<int> result;
        result.push_back(left+1);
        result.push_back(right+1);
        return result;
    }
};



