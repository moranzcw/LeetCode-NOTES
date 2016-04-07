#include <iostream>
#include <cmath>
#include <assert.h>
using namespace std;

class Solution
 {
public:
    int divide(int dividend, int divisor) 
    {
        assert(divisor != 0);
        int res=0;
        int flag=1;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0))
            flag = -1;

        long long divid=abs((long long)dividend);
        long long divi=abs((long long)divisor);
        long long temp=0;

        cout<<flag<<" "<<divid<<" "<<divi<<endl;

        while(divi <= divid)
        {
            int cnt=1;
            temp=divi;

            while( (temp<<=1) <= divid)
            {
                cnt<<=1;
            }
            res += cnt;
            divid -= (temp>>1);
            cout<<res<<endl;
        }

        
        if(res >=2147483647 || res <= -2147483648 )
            return 2147483647;
        return (int)res*flag;
    }
};

int main()
{
    Solution sol;

    cout << sol.divide(-2147483648, 1) << endl;
    return 0;
}