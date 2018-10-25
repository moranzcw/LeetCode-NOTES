class Solution 
{
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        if(A.size() < 3)
            return 0;
        vector<int> diff;
        for(int i=0;i<A.size()-1;i++)
            diff.push_back(A[i+1]-A[i]);
        int count = 0, tempCount = 0;
        for(int i=0;i<diff.size()-1;i++)
        {
            if(diff[i] == diff[i+1])
                tempCount++;
            else
            {
                count += tempCount*(tempCount+1)/2;
                tempCount = 0;
            }
        }
        count += tempCount*(tempCount+1)/2;
        
        return count;
    }
};