class Solution 
{
public:
    int threeSumClosest(vector<int> &num, int target) 
    {
        int closestSum = num[0]+num[1]+num[2];
        sort(num.begin(),num.end());

        for( int num1pos = 0; num1pos<num.size(); num1pos++ )
        {
            for(int num2pos=num1pos+1, num3pos=num.size()-1; num2pos < num3pos;)
            {
                int sum = num[num1pos] + num[num2pos] + num[num3pos];
                if(sum == target)
                    return target;
                
                if(abs(sum-target)<abs(closestSum-target))
                        closestSum = sum;
                
                if(sum < target)
                    num2pos++;
                else
                    num3pos--;
            }
        }
        return closestSum;
    }
};