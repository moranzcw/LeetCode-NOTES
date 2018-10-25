class Solution 
{
public:
    vector<int> grayCode(int n) 
    {
        vector<int> result;
        result.push_back(0);
        for(int i=0; i<n;i++)
        {
            int highest = 1<<i;
            int len = result.size();
            for(int i=len -1; i>=0; i--)
                result.push_back(highest+result[i]);
        }
        return result;
    }
};