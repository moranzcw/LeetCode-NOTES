class Solution 
{
public:
    int lengthOfLastWord(const char *s) 
    {
        int result = 0;
        bool flag = false;
        while(*s != '\0')
        {
            if(*s == ' ')
                flag = true;
            else if(flag == true)
            {
                flag = false;
                result = 1;
            }
            else
                result++;
            s++;
        }
        return result;
    }
};