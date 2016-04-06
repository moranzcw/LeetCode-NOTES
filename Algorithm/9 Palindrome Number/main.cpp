#include <iostream>
using namespace std;

class Solution 
{
public:
    bool isPalindrome(int x)
    {
        if(x < 0)
            return false;
        if( x == 0)
            return true;

        int leftBase = 1;
        int rightBase = 1;
        int temp = x;
        while( (temp /= 10) >0 )
        {
            leftBase *= 10;
        }

        int leftDight = x / leftBase;
        int rightDight = x % 10;
        while(leftBase > rightBase)
        {
            if(leftDight != rightDight)
                return false;
            leftBase /= 10;
            leftDight = (x / leftBase)%10;
            rightBase *= 10;
            rightDight = (x / rightBase)%10;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    cout << sol.isPalindrome(-124321)<<endl;
    return 0;
}