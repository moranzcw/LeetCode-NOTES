class Solution 
{
public:
    string getPermutation(int n, int k) 
    {
        vector<int> nums(n);
        int pCount = 1;
        for(int i = 0 ; i < n; ++i) 
        {
            nums[i] = i + 1;
            pCount *= (i + 1);
        }

        k--;
        string res = "";
        for(int i = 0 ; i < n; i++) 
        {
            pCount = pCount/(n-i);
            int selected = k / pCount;
            res += ('0' + nums[selected]);
            
            for(int j = selected; j < n-i-1; j++)
                nums[j] = nums[j+1];
            k = k % pCount;
        }
        return res;
    }
};