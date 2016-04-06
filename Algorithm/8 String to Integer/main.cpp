#include <iostream>
using namespace std;

class Solution 
{
public:
    int atoi(string str) 
    {
        long int result = 0;
        int digit = 0;
        int sign = 1; 
        int flag = 0;
        while(str[flag] == ' ')
            flag ++;

        if(str[flag] == '+')
        {
            sign = 1;
            flag ++;
        }
        else if( str[flag] >= '0' && str[flag] <= '9' )
            sign = 1;
        else if(str[flag] == '-')
        {
            sign = -1;
            flag ++;
        }
        else
            return 0;

        while(str[flag] >= '0' && str[flag] <= '9' && digit <=10)
        {
            result = result*10 + (str[flag]-'0');
            flag ++;
            digit++;
        }

        result *= sign;
        if ( result > 2147483647 )
            return 2147483647;
        else if( result < -2147483648 )
            return -2147483648;
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.atoi("9223372036854775809")<<endl;
    return 0;
}