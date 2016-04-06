#include <iostream>
using namespace std;

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int strLength = s.length();
        int maxLength = 1;
        int flag = 0;

        bool table[1000][1000] = {false};

        for(int i=0;i<strLength;i++)
            table[i][i] = true;

        for(int i=0;i<strLength-1;i++)
        {
            if(s[i] == s[i+1])
            {
                table[i][i+1] = true;
                flag = i;
                maxLength = 2;
            }
        }

        for(int length = 3;length<=strLength;length++)
        {
            for(int i=0;i<strLength-length+1;i++)
            {
                if(s[i] == s[i+length-1] && table[i+1][i+length-2])
                {
                    table[i][i+length-1] = true;
                    flag = i;
                    maxLength = length;
                }
            }
        }
        return s.substr(flag,maxLength);
    }
};

int main()
{
    Solution sol;
    cout << sol.longestPalindrome("123454321") << endl;
    cout << sol.longestPalindrome("asdfgfdsa") << endl;
    cout << sol.longestPalindrome("zxcvbvcxz") << endl;
    cout << sol.longestPalindrome("zxcvvcxz") << endl;
    cout << sol.longestPalindrome("123321123") << endl;
    cout << sol.longestPalindrome("wrgerg") << endl;
    cout << sol.longestPalindrome("ergrasefwe") << endl;
    cout << sol.longestPalindrome("wer2345") << endl;
    cout << sol.longestPalindrome("1242314") << endl;
    cout << sol.longestPalindrome("3253453") << endl;
    cout << sol.longestPalindrome("23413413") << endl;
}