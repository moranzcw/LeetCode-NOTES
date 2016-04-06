#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int>S;
        S.push(-1);
        int ans=0;
        for(string::size_type i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(ch == '(')
            {
                S.push(i);
            }
            else
            {
                if(S.size()>1)
                {
                    S.pop();
                    int tmp=S.top();
                    ans=max(ans,(int)i-tmp);
                }
                else
                {
                    S.pop();
                    S.push(i);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout<<sol.longestValidParentheses("()()())")<<endl;
    return 0;
}