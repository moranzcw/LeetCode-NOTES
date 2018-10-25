class Solution 
{
public:
    bool isPowerOfFour(int num) 
    {
        return num>0 && !(num&(num-1)) && (num & 0x55555555);
    }
};