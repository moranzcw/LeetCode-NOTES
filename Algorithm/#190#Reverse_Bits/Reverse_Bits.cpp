#include <iostream>
#include <inttypes.h>
using namespace std;

class Solution 
{
public:
    uint32_t reverseBits(uint32_t n) 
    {
        int result = 0;
        for(int i=0;i<32;i++)
        {
            result <<= 1;
            result += n & 1;
            n >>= 1;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout<<sol.reverseBits(43261596)<<endl;
    return 0;
}