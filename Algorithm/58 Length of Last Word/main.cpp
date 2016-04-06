#include <iostream>
using namespace std;

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

int main()
{
    Solution sol;
    cout << sol.lengthOfLastWord("Hello World")<<endl;
    return 0;
}