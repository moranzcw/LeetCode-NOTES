#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution 
{
public:
    int numDecodings(string s) 
    {
        if(s.size() == 0)
        {
            return 0;
        }
        else if(s.size() == 1)
        {
            return s[0] != '0' ? 1 : 0;
        }
        else if(s.size() == 2)
        {
            return (s[0] != '0' && s[1] != '0'? 1 : 0) + ((s[0] != '0' && (char2int(s[0]) * 10 + char2int(s[1])) <= 26) ? 1 : 0);
        }

        int* dp = new int[s.size()];
        dp[0] = s[0] != '0' ? 1 : 0;
        dp[1] = (s[0] != '0' && s[1] != '0'? 1 : 0) + ((s[0] != '0' && (char2int(s[0]) * 10 + char2int(s[1])) <= 26) ? 1 : 0);

        for(int i = 2; i < s.size(); i++)
        {
            dp[i] = 0;
            if(s[i] != '0')
            {
                dp[i] += dp[i-1];
            }

            if(s[i-1] != '0' && (char2int(s[i-1]) * 10 + char2int(s[i])) <= 26)
            {
                dp[i] += dp[i-2];
            }
        }
        return dp[s.size() - 1];
    }

    int char2int(char c)
    {
        return c - '0';
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout<<sol.numDecodings("1234")<<endl;
    return 0;
}