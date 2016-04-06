#include <iostream>
#include <cmath>
using namespace std;

class Solution 
{
public:
    int sqrt(int x) 
    {
        double ans = x;
        while(abs(ans * ans - x) > 0.0001)
            ans = (ans + x / ans) / 2;
        return (int)ans;
    }
};

int main()
{
    Solution sol;
    cout<<sol.sqrt(400)<<endl;
    return 0;
}