class Solution 
{
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        int result=0;
        for(int i=0;i<n&&i<=10;i++)
        {
            int temp = 9;
            for(int j=0;j<i;j++)
            {
                temp *=9-j;
            }
            result += temp;
        }
        result += 1;
        return result;
    }
};