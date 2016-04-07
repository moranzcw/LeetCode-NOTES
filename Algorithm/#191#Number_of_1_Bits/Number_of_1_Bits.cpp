#include <iostream>
#include <stdint.h>

using namespace std;

class Solution 
{
public:
    int hammingWeight(uint32_t n) 
    {
        int result = 0;
        while(n)
        {
            result += n & 0b1? 1:0;
            n >>= 1;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.hammingWeight(11)<<endl;
    return 0;
}