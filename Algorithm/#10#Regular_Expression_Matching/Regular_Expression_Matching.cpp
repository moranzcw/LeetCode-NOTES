#include <iostream>
using namespace std;

class Solution 
{
public:
    bool isMatch(const char *s, const char *p) 
    {
        if(*p =='\0')
            return *s == 0;

        if(*(p+1) != '*')
        {
            if (*s == '\0')
                return false;

            if (*p == *s || *p == '.')
                return isMatch(s+1, p+1);
            else
                return false;
        }
        else
        {
            while (*s == *p || *p == '.')
            {
                if (*s == '\0')
                    break;

                if (isMatch(s, p+2))
                    return true;
                else
                    s++;
            }
            return (isMatch(s, p+2));
        }
    }
};

int main()
{
    Solution sol;
    cout << sol.isMatch("aa","a")<<endl;
    cout << sol.isMatch("aa","aa")<<endl;
    cout << sol.isMatch("aaa","aa")<<endl;
    cout << sol.isMatch("aa","a*")<<endl;
    cout << sol.isMatch("aa",".*")<<endl;
    cout << sol.isMatch("ab",".*")<<endl
    cout << sol.isMatch("aab","c*a*b")<<endl;
    cout << sol.isMatch("a","ab*")<<endl;
    return 0;
}