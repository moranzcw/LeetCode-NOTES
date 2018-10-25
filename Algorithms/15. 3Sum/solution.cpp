class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int> &num) 
    {
        vector<vector<int> > result;
        if(num.size() == 0)
            return result;

        sort(num.begin(),num.end());

        for( int pos1 = 0;pos1<num.size();pos1++)
        {
            for(int pos2 = pos1 + 1, pos3 = num.size() - 1; pos2 < pos3;)
            {
                int sum = num[pos1] + num[pos2] + num[pos3];
                if(sum == 0)
                {
                        vector<int> tempResult;
                        tempResult.push_back(num[pos1]);
                        tempResult.push_back(num[pos2]);
                        tempResult.push_back(num[pos3]);
                        result.push_back(tempResult);

                        while( pos2+1 < pos3 && num[pos2+1] == num[pos2])
                            pos2++;
                        pos2++;
                        
                        while( pos3-1 > pos2 && num[pos3-1] == num[pos3])
                            pos3--;
                        pos3--;
                }
                else if(sum < 0)
                    pos2++;
                else
                    pos3--;
            }
            while( pos1+1 < num.size() && num[pos1+1] == num[pos1])
                pos1++;
        }
        return result;
    }
};