class Solution
{
public:
    int myAtoi(string str) 
    {
        int tempResult,result=0;
        int sign = 1;
        int i=0;
        
        while(i<str.size() && str[i]==' ')
            i++;
        
        if (str[i] == '-' || str[i] == '+') 
            sign = str[i++]=='-'? -1 : 1; 
        
        for(;i<str.size();i++)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                tempResult = result*10 + str[i]-'0';
                if(tempResult/10 != result)
                    return  sign>0 ? INT_MAX:INT_MIN;
                result = tempResult;
            }
            else
                break;
        }
        return result * sign;
    }
};