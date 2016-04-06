#include <iostream>
using namespace std;

class Solution 
{
public:
    int trailingZeroes(int n) 
    {
        int ret = 0;
        while(n)
        {
            ret += n/5;
            n /= 5;
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    cout<<sol.trailingZeroes(12)<<endl;
    return 0;
}