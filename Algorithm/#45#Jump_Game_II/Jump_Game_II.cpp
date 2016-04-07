#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int jump(int A[], int n) 
    {
        int ret = 0;
        int curMax = 0;
        int curRch = 0;
        for(int i = 0; i < n; i ++)
        {
            if(curRch < i)
            {
                ret ++;
                curRch = curMax;
            }
            curMax = max(curMax, A[i]+i);
        }
        return ret;
    }
};

int main()
{
    int A[] = {2,3,1,1,4};
    Solution sol;
    cout<<sol.jump(A,5)<<endl;
    return 0;
}
