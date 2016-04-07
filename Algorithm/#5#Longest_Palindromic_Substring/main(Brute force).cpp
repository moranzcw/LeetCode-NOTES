#include <iostream>
using namespace std;

class Solution 
{
public:
    bool isPalindrome(string  s)
    {
        for(int head = 0,tail = s.length() - 1;head < tail;head++,tail--)
        {
            if(s[head] != s[tail])
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) 
    {
        int maxLength = 0;
        int tempLength = 0;
        int flag = 0;
        for(int i=0;i < s.length();i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                tempLength = j-i+1;
                if (tempLength > maxLength)
                {
                    if(isPalindrome(s.substr(i,tempLength)))
                    {
                        maxLength = tempLength;
                        flag = i;
                    }
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