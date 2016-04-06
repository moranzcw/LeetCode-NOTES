#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
class Solution 
{
public:
    bool isHappy(int n) 
    {
        while(n>6)
        {
            int sum=0;
            while(n)
            {
                sum+=(n%10)*(n%10);
                n/=10;
            }
            n=sum;
        }
        return n==1;
    }
};

int main()
{
    Solution sol;
    cout<<sol.isHappy(19)<<endl;
    return 0;
}