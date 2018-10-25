class Solution 
{
public:
    string toHex(int num) 
    {
        char *str = new char[8];
        sprintf(str, "%x", num);
        return string(str);
    }
};