#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s) 
    {
        stack<char> stk;
        char ascii[256] = {0};
        ascii[40] = 41;
        ascii[91] = 93;
        ascii[123] = 125;
        for(int i=0;i<s.size();i++)
        {
            if(stk.empty() || ascii[stk.top()] != s[i])
                stk.push(s[i]);
            else
                stk.pop();
        }
        if(stk.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    Solution sol;
    cout << sol.isValid("()[]{}") << endl;
    cout << sol.isValid("([)]") << endl;
    cout << sol.isValid("{([(([[(())]]))])}") << endl;
    cout << sol.isValid("([)]") << endl;
    return 0;
}